#include "edao.h"

NAKED VOID CBattle::NakedCopyMagicAndCraftData()
{
    INLINE_ASM
    {
        mov     ecx, [ebp - 08h];
        mov     edx, [ebp + 08h];
        and     dword ptr [ebp - 20h], 0;
        jmp     CBattle::CopyMagicAndCraftData
    }
}

VOID FASTCALL CBattle::CopyMagicAndCraftData(PMONSTER_STATUS MSData)
{
    PUSHORT         MagicList;
    ULONG_PTR       MaxMagicNumber;
    PCRAFT_AI_INFO  Magic;

    if (!IsCustomChar(MSData->CharID))
        return;

    MaxMagicNumber  = countof(MSData->MagicAiInfo);
    Magic           = MSData->MagicAiInfo;
    MagicList       = GetActor()->GetChrMagicList() + MSData->CharID * MaxMagicNumber;

    for (ULONG_PTR Count = countof(MSData->MagicAiInfo); Count; --Count)
    {
        if (Magic->CraftIndex == 0)
            break;

        --MaxMagicNumber;
        ++Magic;
    }

    for (; MaxMagicNumber; ++Magic, ++MagicList, --MaxMagicNumber)
    {
        Magic->CraftIndex = *MagicList;
        Magic->AriaActionIndex  = 6;
        Magic->ActionIndex      = 7;
        Magic->Condition        = 0;
    }

    *(PVOID *)_AddressOfReturnAddress() = (PVOID)0x9A37F4;
}

NAKED VOID CBattle::NakedOverWriteBattleStatusWithChrStatus()
{
    INLINE_ASM
    {
        mov     ecx, [ebp - 08h];
        mov     edx, edi;
        push    eax;
        call    CBattle::OverWriteBattleStatusWithChrStatus
        ret;
    }
}

PMONSTER_STATUS FASTCALL CBattle::OverWriteBattleStatusWithChrStatus(PMONSTER_STATUS MSData, PCHAR_STATUS ChrStatus)
{
    MSData = PtrSub(MSData, FIELD_OFFSET(MONSTER_STATUS, ChrStatus[BattleStatusFinal].MaximumHP));

    PCHAR_STATUS Raw = &MSData->ChrStatus[BattleStatusRaw];
    PCHAR_STATUS Final = &MSData->ChrStatus[BattleStatusFinal];

    *Final = *ChrStatus;

    if (!IsCustomChar(MSData->CharID))
        return MSData;

    Final->MaximumHP    += Raw->MaximumHP   / 2;
    Final->InitialHP    += Raw->InitialHP   / 2;
    Final->MaximumEP    += Raw->MaximumEP   / 2;
    Final->InitialEP    += Raw->InitialEP   / 2;
    Final->STR          += Raw->STR         * 2 / 3;
    Final->DEF          += Raw->DEF         * 2 / 3;
    Final->ATS          += Raw->ATS         * 2 / 3;
    Final->ADF          += Raw->ADF         * 2 / 3;
    Final->DEX          += Raw->DEX         * 2 / 3;
    Final->AGL          += Raw->AGL         * 2 / 3;
    Final->MOV          += Raw->MOV         * 2 / 3;
    Final->SPD          += Raw->SPD         * 2 / 3;

    return MSData;
}

NAKED VOID CBattle::NakedIsChrStatusNeedRefresh()
{
    INLINE_ASM
    {
        mov     ecx, [ebp - 0Ch];
        mov     edx, dword ptr [ebp - 8Ch];
        push    dword ptr [ebp - 25E8h];
        push    eax;
        call    CBattle::IsChrStatusNeedRefresh
        neg     eax;
        ret;
    }
}

BOOL FASTCALL CBattle::IsChrStatusNeedRefresh(ULONG_PTR ChrPosition, PCHAR_STATUS CurrentStatus, ULONG_PTR PrevLevel)
{
    PMONSTER_STATUS MSData;

    MSData = GetMonsterStatus() + ChrPosition;

    if (!IsCustomChar(MSData->CharID))
    {
        return CurrentStatus->Level != PrevLevel;
    }

    return TRUE;
}

NAKED ULONG CBattle::NakedGetChrIdForSCraft()
{
    INLINE_ASM
    {
        mov     ecx, [ebp - 08h];
        call    CBattle::GetActor
        mov     ecx, eax;
        call    CActor::GetPartyChipMap
        mov     ecx, dword ptr [ebp - 14h];
        movzx   ecx, [ecx]MONSTER_STATUS.CharID;
        movzx   eax, [eax + ecx * 2];
        cmp     eax, MINIMUM_CUSTOM_CHAR_ID
        cmovae  ecx, eax;
        ret;
    }
}

ULONG FASTCALL CBattle::GetVoiceChrIdWorker(PMONSTER_STATUS MSData)
{
    ULONG ChrId, PartyId;

    ChrId = MSData->CharID;
    PartyId = GetActor()->GetPartyChipMap()[ChrId];

    return IsCustomChar(ChrId) ? PartyId : ChrId;
}

/*++

  mov     word ptr [ebp-const], r16
  mov     r32, const
  mov     word ptr [ebp-const], r16
  mov     r32, const
  mov     word ptr [ebp-const], r16
  mov     r32, [ebp+8]
  movzx   r32, [r32+0A]

--*/

NAKED VOID CBattle::NakedGetTurnVoiceChrId()
{
    INLINE_ASM
    {
        mov     ecx, [ebp - 0Ch];
        mov     edx, [ebp + 08h];
        call    CBattle::GetVoiceChrIdWorker;
        mov     ecx, eax;
        ret;
    }
}

NAKED VOID CBattle::NakedGetReplySupportVoiceChrId()
{
    INLINE_ASM
    {
        jmp CBattle::NakedGetTurnVoiceChrId;
    }
}

NAKED VOID CBattle::NakedGetRunawayVoiceChrId()
{
    INLINE_ASM
    {
        jmp CBattle::NakedGetTurnVoiceChrId;
    }
}

NAKED VOID CBattle::NakedGetTeamRushVoiceChrId()
{
    INLINE_ASM
    {
        jmp CBattle::NakedGetTurnVoiceChrId;
    }
}

NAKED VOID CBattle::NakedGetSBreakVoiceChrId()
{
    INLINE_ASM
    {
        jmp CBattle::NakedGetTurnVoiceChrId;
    }
}

/************************************************************************
  EDAO
************************************************************************/

NAKED VOID EDAO::NakedGetChrSBreak()
{
    INLINE_ASM
    {
        mov     ecx, eax;
        jmp     EDAO::GetChrSBreak;
    }
}

VOID FASTCALL EDAO::GetChrSBreak(PMONSTER_STATUS MSData)
{
    PCRAFT_AI_INFO Craft;

    if (!IsCustomChar(MSData->CharID))
    {
        MSData->CurrentActionIndex = GetSBreakList()[MSData->CharID];
        return;
    }

    Craft = MSData->SCraftAiInfo;
    for (ULONG_PTR Count = countof(MSData->SCraftAiInfo); Count; ++Craft, --Count)
    {
        if (Craft->CraftIndex == 0)
            break;
    }

    //Craft = Craft == MSData->SCraftAiInfo ? Craft : (Craft - 1);
    Craft = PtrSub(Craft, ((Craft == MSData->SCraftAiInfo) - 1) & sizeof(*Craft));

    MSData->SelectedCraft.AriaActionIndex  = Craft->AriaActionIndex;
    MSData->SelectedCraft.ActionIndex           = Craft->ActionIndex;
    MSData->CurrentActionIndex                  = Craft->CraftIndex;
}

/************************************************************************
  CGlobal
************************************************************************/

PCREATE_INFO CGlobal::GetMagicData(USHORT MagicId)
{
    if (MagicId < MINIMUM_CUSTOM_CRAFT_INDEX)
        return (this->*StubGetMagicData)(MagicId);

    CBattle*        Battle;
    PMONSTER_STATUS MSData;

    Battle = GetEDAO()->GetBattle();

    MSData = &Battle->GetMonsterStatus()[Battle->GetCurrentChrIndex()];

    return &MSData->CraftInfo[MagicId - MINIMUM_CUSTOM_CRAFT_INDEX];
}

PCSTR CGlobal::GetMagicDescription(USHORT MagicId)
{
    if (MagicId < MINIMUM_CUSTOM_CRAFT_INDEX)
        return (this->*StubGetMagicDescription)(MagicId);

    CBattle*        Battle;
    PMONSTER_STATUS MSData;

    Battle = GetEDAO()->GetBattle();

    MSData = &Battle->GetMonsterStatus()[Battle->GetCurrentChrIndex()];

    return MSData->CraftDescription[MagicId - MINIMUM_CUSTOM_CRAFT_INDEX].Description;
}

PBYTE CGlobal::GetMagicQueryTable(USHORT MagicId)
{
    if (MagicId < MINIMUM_CUSTOM_CRAFT_INDEX)
        return (this->*StubGetMagicQueryTable)(MagicId);

    static BYTE StaticMagicQueryTable[] = { 233, 233, 233, 233, 233, 233, 233, 233 };

    return StaticMagicQueryTable;
}



/************************************************************************
  info box
************************************************************************/

VOID THISCALL CBattleInfoBox::SetMonsterInfoBoxSize(LONG X, LONG Y, LONG Width, LONG Height)
{
    TYPE_OF(&CBattleInfoBox::SetMonsterInfoBoxSize) StubSetBoxSize;

    *(PVOID *)&StubSetBoxSize = (PVOID)0x67302C;

    return (this->*StubSetBoxSize)(X, Y, 120, Height);
}

VOID THISCALL CBattleInfoBox::DrawMonsterStatus()
{
    if (GetBattle()->GetCurrentTargetIndex() > MAXIMUM_CHR_NUMBER_IN_BATTLE)
        return;

    (this->*StubDrawMonsterStatus)();

    PCOORD          UpperLeft;
    RECT            Rect;
    PMONSTER_STATUS MSData;

    UpperLeft = GetUpperLeftCoord();

    static RECT debug = { 284, 12, 128, 100 };

    Rect.left   = UpperLeft->X + debug.left;
    Rect.top    = UpperLeft->Y + debug.top;
    Rect.right  = Rect.left + debug.right;
    Rect.bottom = Rect.top + debug.bottom;

    GetEDAO()->DrawRectangle(Rect.left, Rect.top, Rect.right, Rect.bottom, 0x80808080, 0x80808080);

    MSData = GetBattle()->GetMonsterStatus() + GetBattle()->GetCurrentTargetIndex();
}

/************************************************************************
  misc
************************************************************************/

LONG CDECL FormatBattleChrAT(PSTR Buffer, PCSTR Format, LONG Index, LONG No, LONG IcoAT, LONG ObjAT, LONG Pri)
{
    return sprintf(Buffer, "%d", IcoAT);
}

