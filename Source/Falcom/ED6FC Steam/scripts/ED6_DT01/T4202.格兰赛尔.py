﻿from ED6ScenarioHelper import *

def main():
    # 格兰赛尔

    CreateScenaFile(
        FileName            = 'T4202   ._SN',
        MapName             = 'Grancel',
        Location            = 'T4202.x',
        MapIndex            = 1,
        MapDefaultBGM       = "ed60017",
        Flags               = 0,
        EntryFunctionIndex  = 0xFFFF,
        Reserved            = 0,
        IncludedScenario    = [
            '',
            '',
            '',
            '',
            '',
            '',
            '',
            ''
        ],
    )

    BuildStringList(
        '@FileName',                            # 8
        '艾莉茜雅女王',                         # 9
        '尤莉亚中尉',                           # 10
        '约修亚',                               # 11
        '奥利维尔',                             # 12
        '金',                                   # 13
        '洛伦斯少尉',                           # 14
        '洛伦斯残像',                           # 15
        '洛伦斯残像',                           # 16
        '洛伦斯残像',                           # 17
        '洛伦斯残像',                           # 18
        '头盔',                                 # 19
    )

    DeclEntryPoint(
        Unknown_00              = 0,
        Unknown_04              = 0,
        Unknown_08              = 6000,
        Unknown_0C              = 4,
        Unknown_0E              = 0,
        Unknown_10              = 0,
        Unknown_14              = 9500,
        Unknown_18              = -10000,
        Unknown_1C              = 0,
        Unknown_20              = 0,
        Unknown_24              = 0,
        Unknown_28              = 2800,
        Unknown_2C              = 262,
        Unknown_30              = 45,
        Unknown_32              = 0,
        Unknown_34              = 360,
        Unknown_36              = 0,
        Unknown_38              = 0,
        Unknown_3A              = 0,
        InitScenaIndex          = 0,
        InitFunctionIndex       = 0,
        EntryScenaIndex         = 0,
        EntryFunctionIndex      = 1,
    )


    AddCharChip(
        'ED6_DT07/CH02010 ._CH',             # 00
        'ED6_DT07/CH02090 ._CH',             # 01
        'ED6_DT07/CH00010 ._CH',             # 02
        'ED6_DT07/CH00030 ._CH',             # 03
        'ED6_DT07/CH00070 ._CH',             # 04
        'ED6_DT07/CH00480 ._CH',             # 05
        'ED6_DT07/CH00482 ._CH',             # 06
        'ED6_DT07/CH00100 ._CH',             # 07
        'ED6_DT07/CH00101 ._CH',             # 08
        'ED6_DT07/CH00120 ._CH',             # 09
        'ED6_DT07/CH00121 ._CH',             # 0A
        'ED6_DT07/CH00140 ._CH',             # 0B
        'ED6_DT07/CH00141 ._CH',             # 0C
        'ED6_DT07/CH02200 ._CH',             # 0D
        'ED6_DT07/CH00484 ._CH',             # 0E
        'ED6_DT07/CH00104 ._CH',             # 0F
        'ED6_DT07/CH00124 ._CH',             # 10
        'ED6_DT07/CH00144 ._CH',             # 11
        'ED6_DT06/CH20035 ._CH',             # 12
        'ED6_DT06/CH20036 ._CH',             # 13
        'ED6_DT06/CH20037 ._CH',             # 14
        'ED6_DT06/CH20044 ._CH',             # 15
        'ED6_DT07/CH00481 ._CH',             # 16
        'ED6_DT07/CH00011 ._CH',             # 17
        'ED6_DT07/CH00031 ._CH',             # 18
        'ED6_DT07/CH00071 ._CH',             # 19
        'ED6_DT06/CH20114 ._CH',             # 1A
        'ED6_DT06/CH20115 ._CH',             # 1B
    )

    AddCharChipPat(
        'ED6_DT07/CH02010P._CP',             # 00
        'ED6_DT07/CH02090P._CP',             # 01
        'ED6_DT07/CH00010P._CP',             # 02
        'ED6_DT07/CH00030P._CP',             # 03
        'ED6_DT07/CH00070P._CP',             # 04
        'ED6_DT07/CH00480P._CP',             # 05
        'ED6_DT07/CH00482P._CP',             # 06
        'ED6_DT07/CH00100P._CP',             # 07
        'ED6_DT07/CH00101P._CP',             # 08
        'ED6_DT07/CH00120P._CP',             # 09
        'ED6_DT07/CH00121P._CP',             # 0A
        'ED6_DT07/CH00140P._CP',             # 0B
        'ED6_DT07/CH00141P._CP',             # 0C
        'ED6_DT07/CH02200P._CP',             # 0D
        'ED6_DT07/CH00484P._CP',             # 0E
        'ED6_DT07/CH00104P._CP',             # 0F
        'ED6_DT07/CH00124P._CP',             # 10
        'ED6_DT07/CH00144P._CP',             # 11
        'ED6_DT06/CH20035P._CP',             # 12
        'ED6_DT06/CH20036P._CP',             # 13
        'ED6_DT06/CH20037P._CP',             # 14
        'ED6_DT06/CH20044P._CP',             # 15
        'ED6_DT07/CH00481P._CP',             # 16
        'ED6_DT07/CH00011P._CP',             # 17
        'ED6_DT07/CH00031P._CP',             # 18
        'ED6_DT07/CH00071P._CP',             # 19
        'ED6_DT06/CH20114P._CP',             # 1A
        'ED6_DT06/CH20115P._CP',             # 1B
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 0,
        ChipIndex           = 0x0,
        NpcIndex            = 0x181,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 1,
        ChipIndex           = 0x1,
        NpcIndex            = 0x181,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 2,
        ChipIndex           = 0x2,
        NpcIndex            = 0x181,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 3,
        ChipIndex           = 0x3,
        NpcIndex            = 0x181,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 4,
        ChipIndex           = 0x4,
        NpcIndex            = 0x181,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 13,
        ChipIndex           = 0xD,
        NpcIndex            = 0x181,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 6,
        ChipIndex           = 0x6,
        NpcIndex            = 0x180,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 6,
        ChipIndex           = 0x6,
        NpcIndex            = 0x180,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 6,
        ChipIndex           = 0x6,
        NpcIndex            = 0x180,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 6,
        ChipIndex           = 0x6,
        NpcIndex            = 0x180,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )

    DeclNpc(
        X                   = 0,
        Z                   = 0,
        Y                   = 0,
        Direction           = 180,
        Unknown2            = 0,
        Unknown3            = 21,
        ChipIndex           = 0x15,
        NpcIndex            = 0x181,
        InitFunctionIndex   = -1,
        InitScenaIndex      = -1,
        TalkFunctionIndex   = -1,
        TalkScenaIndex      = -1,
    )


    ScpFunction(
        "Function_0_2EA",          # 00, 0
        "Function_1_312",          # 01, 1
        "Function_2_35D",          # 02, 2
        "Function_3_2DA6",         # 03, 3
        "Function_4_2DD4",         # 04, 4
        "Function_5_2E7B",         # 05, 5
        "Function_6_2F27",         # 06, 6
        "Function_7_2FB7",         # 07, 7
    )


    def Function_0_2EA(): pass

    label("Function_0_2EA")

    Switch(
        (scpexpr(EXPR_PUSH_VALUE_INDEX, 0x0), scpexpr(EXPR_END)),
        (100, "loc_2F6"),
        (SWITCH_DEFAULT, "loc_311"),
    )


    label("loc_2F6")

    Jc((scpexpr(EXPR_TEST_SCENA_FLAGS, MakeScenarioFlags(0xCC, 6)), scpexpr(EXPR_EQUZ), scpexpr(EXPR_TEST_SCENA_FLAGS, MakeScenarioFlags(0xCC, 5)), scpexpr(EXPR_NEQUZ_I64), scpexpr(EXPR_END)), "loc_30E")
    OP_22(0x1C3, 0x1, 0x64)
    OP_A2(0x666)
    Event(0, 2)

    label("loc_30E")

    Jump("loc_311")

    label("loc_311")

    Return()

    # Function_0_2EA end

    def Function_1_312(): pass

    label("Function_1_312")

    Jc((scpexpr(EXPR_PUSH_VALUE_INDEX, 0x29), scpexpr(EXPR_PUSH_LONG, 0x39A), scpexpr(EXPR_EQU), scpexpr(EXPR_END)), "loc_32F")
    OP_22(0x1C3, 0x1, 0x64)
    OP_4F(0x1, (scpexpr(EXPR_PUSH_LONG, 0x51), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    Jump("loc_35C")

    label("loc_32F")

    Jc((scpexpr(EXPR_TEST_SCENA_FLAGS, MakeScenarioFlags(0xCC, 0)), scpexpr(EXPR_TEST_SCENA_FLAGS, MakeScenarioFlags(0xCD, 2)), scpexpr(EXPR_EQUZ), scpexpr(EXPR_NEQUZ_I64), scpexpr(EXPR_END)), "loc_347")
    OP_4F(0x1, (scpexpr(EXPR_PUSH_LONG, 0x59), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    Jump("loc_35C")

    label("loc_347")

    Jc((scpexpr(EXPR_TEST_SCENA_FLAGS, MakeScenarioFlags(0xCD, 2)), scpexpr(EXPR_TEST_SCENA_FLAGS, MakeScenarioFlags(0xCD, 3)), scpexpr(EXPR_EQUZ), scpexpr(EXPR_NEQUZ_I64), scpexpr(EXPR_END)), "loc_35C")
    OP_4F(0x1, (scpexpr(EXPR_PUSH_LONG, 0x58), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))

    label("loc_35C")

    Return()

    # Function_1_312 end

    def Function_2_35D(): pass

    label("Function_2_35D")

    EventBegin(0x0)
    OP_28(0x4E, 0x1, 0x8)
    OP_6D(2050, 12000, 54240, 0)
    OP_67(0, 11000, -10000, 0)
    OP_6B(2400, 0)
    OP_6C(54000, 0)
    OP_6E(280, 0)
    ClearChrFlags(0x8, 0x80)
    ClearChrFlags(0xD, 0x80)
    SetChrPos(0x8, 2170, 12000, 62700, 0)
    SetChrPos(0xD, 4110, 12000, 65390, 180)
    SetChrPos(0x101, 1870, 12000, 45230, 0)
    SetChrPos(0x105, 1870, 12000, 45230, 0)
    SetChrPos(0x103, 1870, 12000, 45230, 0)
    SetChrChipByIndex(0x101, 7)
    SetChrChipByIndex(0x103, 9)
    SetChrChipByIndex(0x105, 11)
    OP_9F(0x105, 0xFF, 0xFF, 0xFF, 0x0, 0x0)
    OP_9F(0x101, 0xFF, 0xFF, 0xFF, 0x0, 0x0)
    OP_9F(0x103, 0xFF, 0xFF, 0xFF, 0x0, 0x0)
    ClearMapFlags(0x800)
    FadeToBright(1000, 0)

    def lambda_445():
        OP_6D(1870, 12000, 56440, 3000)
        ExitThread()

    QueueWorkItem(0x101, 3, lambda_445)

    def lambda_45D():
        OP_9F(0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F4)
        ExitThread()

    QueueWorkItem(0x105, 2, lambda_45D)

    def lambda_46F():
        OP_8E(0xFE, 0x730, 0x2EE0, 0xD566, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x105, 1, lambda_46F)
    Sleep(500)

    def lambda_48F():
        OP_9F(0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F4)
        ExitThread()

    QueueWorkItem(0x101, 2, lambda_48F)

    def lambda_4A1():
        OP_8E(0xFE, 0xBCC, 0x2EE0, 0xD0AC, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_4A1)
    Sleep(500)

    def lambda_4C1():
        OP_9F(0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F4)
        ExitThread()

    QueueWorkItem(0x103, 2, lambda_4C1)

    def lambda_4D3():
        OP_8E(0xFE, 0x26C, 0x2EE0, 0xD19C, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x103, 1, lambda_4D3)
    OP_4F(0x1, (scpexpr(EXPR_PUSH_LONG, 0x0), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    OP_20(0xBB8)
    WaitChrThread(0x101, 0x3)

    ChrTalk(
        0x105,
        "#043F祖母大人，您没事吧？\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        "#508F我们来救您了，女王陛下！\x02",
    )

    CloseMessageWindow()
    TurnDirection(0x8, 0x105, 400)

    ChrTalk(
        0x8,
        (
            "#093F科洛蒂娅……还有艾丝蒂尔……\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    NpcTalk(
        0xD,
        "男人的声音",
        (
            "#4P总算来了啊……\x01",
            "我已经等的有些不耐烦了。\x02",
        )
    )

    CloseMessageWindow()
    OP_62(0x101, 0x0, 2000, 0x2, 0x7, 0x50, 0x1)
    OP_22(0x27, 0x0, 0x64)
    OP_62(0x105, 0x0, 2000, 0x2, 0x7, 0x50, 0x1)
    OP_22(0x27, 0x0, 0x64)
    OP_62(0x103, 0x0, 2000, 0x2, 0x7, 0x50, 0x1)
    OP_22(0x27, 0x0, 0x64)
    Sleep(1000)
    OP_1D(0x51)

    def lambda_5FB():
        OP_8E(0xD, 0xAD2, 0x2EE0, 0xF3E8, 0x7D0, 0x0)
        ExitThread()

    QueueWorkItem(0xD, 2, lambda_5FB)

    def lambda_616():

        label("loc_616")

        TurnDirection(0xD, 0x105, 0)
        OP_48()
        Jump("loc_616")

    QueueWorkItem2(0xD, 1, lambda_616)

    def lambda_627():
        OP_6D(2100, 13150, 60270, 3000)
        ExitThread()

    QueueWorkItem(0x101, 2, lambda_627)

    def lambda_63F():
        OP_6C(45000, 3000)
        ExitThread()

    QueueWorkItem(0x101, 3, lambda_63F)

    def lambda_64F():
        OP_6E(359, 3000)
        ExitThread()

    QueueWorkItem(0x105, 2, lambda_64F)

    def lambda_65F():
        OP_67(0, 6640, -10000, 3000)
        ExitThread()

    QueueWorkItem(0x105, 3, lambda_65F)

    def lambda_677():
        OP_6B(2300, 3000)
        ExitThread()

    QueueWorkItem(0x103, 2, lambda_677)
    Sleep(800)

    def lambda_68C():
        OP_8F(0xFE, 0x88E, 0x2EE0, 0xF744, 0x3E8, 0x0)
        ExitThread()

    QueueWorkItem(0x8, 2, lambda_68C)
    Sleep(200)

    def lambda_6AC():
        OP_8E(0xFE, 0x83E, 0x2EE0, 0xDDC2, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x105, 1, lambda_6AC)
    Sleep(110)

    def lambda_6CC():
        OP_8E(0xFE, 0xD20, 0x2EE0, 0xDFB6, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_6CC)
    Sleep(100)

    def lambda_6EC():
        OP_8E(0xFE, 0x280, 0x2EE0, 0xE074, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x103, 1, lambda_6EC)
    WaitChrThread(0x101, 0x2)

    ChrTalk(
        0x101,
        (
            "#580F洛、洛伦斯少尉！\x01",
            "你为什么会在这种地方……\x02",
        )
    )

    CloseMessageWindow()
    OP_44(0xD, 0xFF)

    ChrTalk(
        0xD,
        (
            "#280F#5P呵呵……\x01",
            "我的任务是保护女王陛下。\x02\x03",
            "出现在这里也没什么不可思议的吧？\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#005F别开玩笑了！\x02\x03",
            "不管你的实力有多强，\x01",
            "我们这边可是有三个人哦！\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x103,
        (
            "#023F怎么会，这个男人……\x01",
            "身上散发出如此强烈的压迫感。\x02\x03",
            "他究竟是什么人？\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#005F这个人就是情报部特务部队队长\x01",
            "洛伦斯·博格少尉！\x02\x03",
            "过去是猎兵团的一员，\x01",
            "后来被理查德上校招入麾下！\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#280F#5P哦，竟然调查到如此程度了。\x02\x03",
            "不愧是Ｓ级游击士\x01",
            "卡西乌斯·布莱特的女儿。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        "#580F#3S！！！\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x103,
        (
            "#022F居然连从未向外界公布过的\x01",
            "老师的级别也知道……\x02\x03",
            "这个男人，不是等闲之辈啊。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#280F#5P呵呵……\x01",
            "你的事情我也很清楚。\x02\x03",
            "级别Ｃ、外号『银闪』的\x01",
            "雪拉扎德·哈维。\x02\x03",
            "近日似乎就要升格为级别Ｂ了。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x103,
        "#022F…………………………………\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        (
            "#043F对、对不起……\x01",
            "请把祖母大人还给我好吗。\x02\x03",
            "如果你只是被上校所雇佣的话，\x01",
            "现在已经没有必要再战斗下去了啊。\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#280F#5P驱动着这个世界的，\x01",
            "并非只有眼睛能够看到的东西。\x02\x03",
            "就像只观察结晶回路的轮盘\x01",
            "是无法知晓齿轮的运动一样……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        "#044F啊……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#281F#5P听好了，科洛蒂娅公主。\x02\x03",
            "所谓国家，\x01",
            "就如同巨大而复杂的导力器。\x02\x03",
            "人们如同身处其中、蕴含力量的结晶回路，\x01",
            "组织、制度则是调动力量的齿轮……\x02\x03",
            "而将其包裹在一起的国土就是导力器的框架。\x02\x03",
            "对于这些知识，如果不能掌握，\x01",
            "那你就没有资格成为一国之主的女王。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        "#043F！？\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#094F的确是相当形象的比喻啊。\x02\x03",
            "#090F而且……\x01",
            "也许就像你所说的那样。\x02\x03",
            "真没有想到在这样的地方\x01",
            "竟然能听到如此独到的国家论……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#280F#5P呵呵……刚才献丑了。\x01",
            "这些话对于陛下您来说似乎没有必要。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#007F虽然不太明白是怎么一回事……\x02\x03",
            "#002F不过看起来，\x01",
            "你没有打算要释放女王陛下的意思吧？\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        "#280F#5P就算如此……你们又能怎样？\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#005F那还用说……\x01",
            "拼尽全力也要救回女王陛下！\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x103,
        (
            "#024F没错……\x01",
            "既然到了这里，就没有退缩的理由。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        (
            "#049F虽然从你身上感觉不到什么敌意……\x01",
            "　\x02\x03",
            "#042F但是，为了将祖母大人救回来，\x01",
            "我会毫不犹豫向你出剑的！\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#280F#5P呵呵，不错啊……\x02\x03",
            "既然这样的话，\x01",
            "我也要拿出一些真正的实力来了。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        "#004F啊……！？\x02",
    )

    CloseMessageWindow()
    OP_20(0x5DC)
    SetChrFlags(0xD, 0x20)
    SetChrFlags(0xD, 0x2)
    SetChrSubChip(0xD, 0)
    SetChrChipByIndex(0xD, 18)

    def lambda_E82():
        OP_99(0xFE, 0x0, 0x1, 0x3E8)
        ExitThread()

    QueueWorkItem(0xD, 1, lambda_E82)
    Sleep(500)
    SetChrFlags(0x12, 0x20)
    SetChrFlags(0x12, 0x2)
    SetChrFlags(0x12, 0x4)
    SetChrFlags(0x12, 0x40)
    SetChrSubChip(0x12, 0)
    SetChrPos(0x12, 3300, 12300, 62320, 0)
    OP_99(0xD, 0x1, 0x4, 0x514)
    ClearChrFlags(0x12, 0x80)

    def lambda_ECF():
        OP_99(0xFE, 0x5, 0x7, 0x514)
        ExitThread()

    QueueWorkItem(0xD, 1, lambda_ECF)
    OP_8E(0x12, 0xDAC, 0x2EE0, 0xF30C, 0x1388, 0x0)
    OP_22(0xB1, 0x0, 0x64)

    def lambda_EF8():
        OP_99(0xFE, 0x0, 0x7, 0x4B0)
        ExitThread()

    QueueWorkItem(0x12, 1, lambda_EF8)
    OP_96(0x12, 0x1400, 0x2EE0, 0xF190, 0x2BC, 0x5DC)
    OP_96(0x12, 0x16D0, 0x2EE0, 0xF050, 0x190, 0x5DC)

    def lambda_F36():
        OP_99(0xFE, 0x0, 0x7, 0x514)
        ExitThread()

    QueueWorkItem(0x12, 1, lambda_F36)
    OP_8E(0x12, 0x1964, 0x2EE0, 0xEF74, 0x2BC, 0x0)
    Sleep(500)

    ChrTalk(
        0xD,
        "#284F#5P…………………………\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        "#580F……银发……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x103,
        (
            "#022F不对………………\x01",
            "……是苍金色……\x02\x03",
            "这个男人……\x01",
            "看起来应该是北方出生的。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#285F#5P呵呵……\x01",
            "没错，的确是北方。\x02\x03",
            "不过离这里也不算非常的远。\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        "#043F啊……\x02",
    )

    CloseMessageWindow()
    OP_1D(0x2B)

    def lambda_1046():
        OP_6B(2000, 1000)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_1046)
    Sleep(500)
    Fade(500)
    ClearChrFlags(0xD, 0x2)
    OP_51(0xD, 0x8, (scpexpr(EXPR_PUSH_LONG, 0xB), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0xD, 6)
    OP_0D()
    Sleep(500)

    ChrTalk(
        0xD,
        (
            "#286F#5P虽然你们是女性，\x01",
            "但我也没打算要手下留情……\x02\x03",
            "#283F……接招。\x02",
        )
    )

    CloseMessageWindow()
    ClearChrFlags(0xD, 0x20)
    SetChrChipByIndex(0xD, 22)
    OP_51(0xD, 0x8, (scpexpr(EXPR_PUSH_LONG, 0x0), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))

    def lambda_10DA():
        OP_92(0xFE, 0x105, 0x3E8, 0x1F40, 0x0)
        ExitThread()

    QueueWorkItem(0xD, 1, lambda_10DA)

    def lambda_10EF():
        OP_6D(2100, 13150, 57270, 500)
        ExitThread()

    QueueWorkItem(0xD, 2, lambda_10EF)
    Sleep(400)
    OP_44(0xD, 0xFF)
    OP_44(0x101, 0xFF)
    OP_44(0x103, 0xFF)
    OP_44(0x105, 0xFF)
    SetChrFlags(0xD, 0x20)
    Battle(0x39A, 0x0, 0x0, 0x0, 0xFF)
    EventBegin(0x0)
    SetChrPos(0x101, 3360, 12000, 57270, 0)
    SetChrPos(0x105, 2110, 12000, 56770, 0)
    SetChrPos(0x103, 640, 12000, 57460, 0)
    SetChrSubChip(0xD, 0)
    SetChrChipByIndex(0xD, 5)
    Switch(
        (scpexpr(EXPR_PUSH_VALUE_INDEX, 0x3), scpexpr(EXPR_END)),
        (0, "loc_1173"),
        (SWITCH_DEFAULT, "loc_15C5"),
    )


    label("loc_1173")

    LoadEffect(0x0, "monster\\\\msc0280.eff")
    OP_28(0x4E, 0x1, 0x10)
    OP_51(0xD, 0x8, (scpexpr(EXPR_PUSH_LONG, 0x3), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0xD, 14)
    SetChrPos(0xD, 2220, 12000, 61180, 180)
    OP_2B(0x4D, 0x3)
    OP_6B(2300, 0)
    FadeToBright(1000, 0)
    OP_0D()

    ChrTalk(
        0xD,
        (
            "#286F#5P真令人吃惊啊……\x01",
            "没想到你们可以达到如此程度。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#582F呼呼……\x02\x03",
            "#005F你、你这家伙！\x01",
            "当初决赛的时候没有尽全力吧！？\x02\x03",
            "和那时相比，简直强悍得判若两人！\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x103,
        (
            "#522F竟、竟然可以打败这样的怪物……\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        "#049F的、的确难以置信啊……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#284F#5P艾丝蒂尔·布莱特……\x01",
            "刚才对你太过轻视，在下深表歉意。\x02\x03",
            "你如果能继续这么走下去……\x01",
            "达到你父亲那种境界也未尝不可。　　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        "#004F什么……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        "#285F#5P不过……现在还有一定差距。\x02",
    )

    CloseMessageWindow()

    def lambda_137D():
        OP_6D(2400, 12000, 57540, 2000)
        ExitThread()

    QueueWorkItem(0x8, 2, lambda_137D)
    OP_99(0xD, 0x3, 0x0, 0x7D0)
    OP_51(0xD, 0x8, (scpexpr(EXPR_PUSH_LONG, 0xB), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0xD, 6)
    OP_9F(0xE, 0xFF, 0xFF, 0xFF, 0xC8, 0x0)
    OP_9F(0xF, 0xFF, 0xFF, 0xFF, 0x96, 0x0)
    OP_9F(0x10, 0xFF, 0xFF, 0xFF, 0x64, 0x0)
    OP_9F(0x11, 0xFF, 0xFF, 0xFF, 0x32, 0x0)
    SetChrPos(0xE, 2220, 12000, 61180, 180)
    SetChrPos(0xF, 2220, 12000, 61180, 180)
    SetChrPos(0x10, 2220, 12000, 61180, 180)
    SetChrPos(0x11, 2220, 12000, 61180, 180)
    OP_43(0xD, 0x1, 0x0, 0x5)
    Sleep(90)
    OP_43(0xE, 0x1, 0x0, 0x4)
    Sleep(90)
    OP_43(0xF, 0x1, 0x0, 0x4)
    Sleep(90)
    OP_43(0x10, 0x1, 0x0, 0x4)
    Sleep(90)
    OP_43(0x11, 0x1, 0x0, 0x4)
    OP_A6(0x0)

    def lambda_1458():
        OP_67(0, 7820, -10000, 700)
        ExitThread()

    QueueWorkItem(0x8, 1, lambda_1458)

    def lambda_1470():
        OP_6C(24000, 700)
        ExitThread()

    QueueWorkItem(0x8, 3, lambda_1470)
    OP_A6(0x1)
    Sleep(130)
    PlayEffect(0x0, 0xFF, 0xFF, 2360, 12050, 57260, 0, 0, 0, 1000, 1000, 1000, 0xFF, 0, 0, 0, 0)
    OP_A6(0x2)
    OP_51(0x105, 0x8, (scpexpr(EXPR_PUSH_LONG, 0x0), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0x105, 17)
    TurnDirection(0x105, 0xD, 0)

    def lambda_14D7():
        OP_94(0x1, 0xFE, 0xB4, 0x3E8, 0x1B58, 0x0)
        ExitThread()

    QueueWorkItem(0x105, 2, lambda_14D7)

    def lambda_14ED():
        OP_99(0xFE, 0x0, 0x3, 0x7D0)
        ExitThread()

    QueueWorkItem(0x105, 1, lambda_14ED)
    OP_51(0x103, 0x8, (scpexpr(EXPR_PUSH_LONG, 0x0), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0x103, 16)
    TurnDirection(0x103, 0xD, 0)

    def lambda_1514():
        OP_94(0x1, 0xFE, 0xB4, 0x3E8, 0x1B58, 0x0)
        ExitThread()

    QueueWorkItem(0x103, 2, lambda_1514)

    def lambda_152A():
        OP_99(0xFE, 0x0, 0x3, 0x7D0)
        ExitThread()

    QueueWorkItem(0x103, 1, lambda_152A)
    OP_51(0x101, 0x8, (scpexpr(EXPR_PUSH_LONG, 0x0), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0x101, 15)
    TurnDirection(0x101, 0xD, 0)

    def lambda_1551():
        OP_94(0x1, 0xFE, 0xB4, 0x3E8, 0x1B58, 0x0)
        ExitThread()

    QueueWorkItem(0x101, 2, lambda_1551)

    def lambda_1567():
        OP_99(0xFE, 0x0, 0x3, 0x7D0)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_1567)
    Sleep(500)

    ChrTalk(
        0x101,
        "#504F#2P#8A啊啊！？\x05\x02",
    )


    ChrTalk(
        0x103,
        "#523F#8A呜……！\x05\x02",
    )


    ChrTalk(
        0x105,
        "#541F#8A呀啊……！\x05\x02",
    )

    Sleep(2500)
    Jump("loc_177C")

    label("loc_15C5")

    OP_28(0x4E, 0x1, 0x20)
    OP_6C(24000, 0)
    OP_67(0, 7820, -10000, 0)
    OP_6D(2400, 12000, 57540, 0)
    OP_6B(2300, 0)
    SetChrChipByIndex(0x105, 17)
    SetChrChipByIndex(0x103, 16)
    SetChrChipByIndex(0x101, 15)
    SetChrSubChip(0x105, 2)
    SetChrSubChip(0x103, 2)
    SetChrSubChip(0x101, 2)
    SetChrPos(0xD, 1970, 12000, 58030, 182)
    SetChrPos(0x105, 1500, 12000, 55600, 359)
    SetChrPos(0x103, -500, 12000, 57130, 49)
    SetChrPos(0x101, 4000, 12000, 56700, 290)
    FadeToBright(1000, 0)
    OP_0D()

    ChrTalk(
        0xD,
        (
            "#284F#5P……真让人失望。\x02\x03",
            "原本还以为能有场势均力敌的战斗……\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#581F#4P为、为什么……\x02\x03",
            "和当初的决赛相比简直判若两人……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x103,
        (
            "#522F……可能那时候\x01",
            "他根本还没有出尽全力吧……\x02\x03",
            "如此强大的力量……\x01",
            "或许已经可以和老师匹敌了……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        (
            "#049F祖母大人……\x01",
            "……对不起……\x02",
        )
    )

    CloseMessageWindow()
    Jump("loc_177C")

    label("loc_177C")


    ChrTalk(
        0x8,
        (
            "#095F#6P科洛蒂娅！艾丝蒂尔！\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    def lambda_17A7():
        OP_8E(0xFE, 0x6F4, 0x2EE0, 0xF1EA, 0xBB8, 0x0)
        ExitThread()

    QueueWorkItem(0x8, 1, lambda_17A7)
    Sleep(200)
    SetChrFlags(0xE, 0x80)
    SetChrFlags(0xF, 0x80)
    SetChrFlags(0x10, 0x80)
    SetChrFlags(0x11, 0x80)

    def lambda_17DB():
        OP_6D(2150, 12000, 59650, 1000)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_17DB)
    OP_8C(0xD, 0, 400)
    WaitChrThread(0x101, 0x1)

    ChrTalk(
        0xD,
        (
            "#284F#4P陛下，请少安毋躁。\x01",
            "我只是让她们暂时不能动而已。\x02\x03",
            "并没有生命危险。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#093F#5P…………………………\x02\x03",
            "那双眼眸……\x01",
            "为何会有那么深邃的颜色呢。\x02\x03",
            "明明还如此年轻……\x01",
            "可却好像经历过巨大的苦难一样。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#283F#4P…………………………\x02\x03",
            "#286F女王啊，\x01",
            "您并没有怜悯我的资格。\x02\x03",
            "对于『哈梅尔』这个名字，\x01",
            "我想您应该不会感到陌生吧……\x02",
        )
    )

    CloseMessageWindow()
    OP_62(0x8, 0x0, 2000, 0x2, 0x7, 0x50, 0x1)
    OP_22(0x27, 0x0, 0x64)
    Sleep(1000)

    ChrTalk(
        0x8,
        "#097F#5P#3S！？\x02",
    )

    CloseMessageWindow()
    TurnDirection(0xD, 0x105, 400)

    def lambda_1983():

        label("loc_1983")

        TurnDirection(0xFE, 0x105, 0)
        OP_48()
        Jump("loc_1983")

    QueueWorkItem2(0xD, 1, lambda_1983)

    def lambda_1994():
        OP_6D(2150, 12000, 61000, 1000)
        ExitThread()

    QueueWorkItem(0x101, 2, lambda_1994)
    OP_22(0xA4, 0x0, 0x64)
    OP_96(0xD, 0xB0E, 0x2EE0, 0xF1FE, 0x1F4, 0x1388)
    TurnDirection(0x8, 0xD, 400)
    TurnDirection(0x105, 0xD, 0)

    def lambda_19D6():
        OP_99(0x105, 0x3, 0x0, 0x3E8)
        ExitThread()

    QueueWorkItem(0x105, 1, lambda_19D6)
    Sleep(100)
    TurnDirection(0x101, 0xD, 0)

    def lambda_19F2():
        OP_99(0x101, 0x3, 0x0, 0x3E8)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_19F2)
    Sleep(100)
    TurnDirection(0x103, 0xD, 0)

    def lambda_1A0E():
        OP_99(0x103, 0x3, 0x0, 0x3E8)
        ExitThread()

    QueueWorkItem(0x103, 1, lambda_1A0E)
    WaitChrThread(0x105, 0x1)
    SetChrChipByIndex(0x105, 11)
    WaitChrThread(0x101, 0x1)
    SetChrChipByIndex(0x101, 7)
    WaitChrThread(0x103, 0x1)
    SetChrChipByIndex(0x103, 9)
    WaitChrThread(0x101, 0x2)

    ChrTalk(
        0xD,
        (
            "#285F好了，差不多是时候了。\x02\x03",
            "如大家所愿，\x01",
            "我将女王完好奉还给你们。\x02",
        )
    )

    CloseMessageWindow()
    OP_44(0xD, 0xFF)

    ChrTalk(
        0x101,
        "#580F啊……！？\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#286F如果还想阻止上校的话，\x01",
            "劝你们赶快前往地下去吧。\x02\x03",
            "虽然可能已经来不及了……\x02\x03",
            "不过也许还能减少无谓的伤亡。\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#092F#3P地下……\x02\x03",
            "难道是说从那个地方降落到地下？\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xD,
        (
            "#285F呵呵……现在的您对其中的含义，\x01",
            "应该是清楚得不能再清楚了吧。\x02\x03",
            "为他们指引前进的道路吧。\x02\x03",
            "#286F……那么，再会了。\x02",
        )
    )

    CloseMessageWindow()
    LoadEffect(0x0, "map\\\\evsepith.eff")

    def lambda_1BDD():

        label("loc_1BDD")

        TurnDirection(0xFE, 0xD, 0)
        OP_48()
        Jump("loc_1BDD")

    QueueWorkItem2(0x8, 1, lambda_1BDD)
    ClearChrFlags(0xD, 0x20)
    SetChrFlags(0xD, 0x4)

    def lambda_1BF8():
        OP_6D(1740, 12000, 71200, 2000)
        ExitThread()

    QueueWorkItem(0x101, 3, lambda_1BF8)

    def lambda_1C10():
        OP_6E(359, 2500)
        ExitThread()

    QueueWorkItem(0x101, 2, lambda_1C10)

    def lambda_1C20():
        OP_67(0, 6450, -10000, 2500)
        ExitThread()

    QueueWorkItem(0xD, 3, lambda_1C20)

    def lambda_1C38():
        OP_6C(90000, 2500)
        ExitThread()

    QueueWorkItem(0xD, 2, lambda_1C38)
    OP_20(0x5DC)
    SetChrFlags(0xD, 0x20)
    OP_8C(0xD, 0, 600)
    ClearChrFlags(0xD, 0x20)
    OP_9F(0xE, 0xFF, 0xFF, 0xFF, 0x78, 0x0)
    OP_9F(0xF, 0xFF, 0xFF, 0xFF, 0x64, 0x0)
    OP_9F(0x10, 0xFF, 0xFF, 0xFF, 0x50, 0x0)
    OP_9F(0x11, 0xFF, 0xFF, 0xFF, 0x3C, 0x0)
    SetChrPos(0xE, 2830, 12000, 61950, 0)
    SetChrPos(0xF, 2830, 12000, 61950, 0)
    SetChrPos(0x10, 2830, 12000, 61950, 0)
    SetChrPos(0x11, 2830, 12000, 61950, 0)
    OP_43(0xD, 0x0, 0x0, 0x7)
    Sleep(150)
    OP_43(0xE, 0x0, 0x0, 0x6)
    Sleep(150)
    OP_43(0xF, 0x0, 0x0, 0x6)
    Sleep(150)
    OP_43(0x10, 0x0, 0x0, 0x6)
    Sleep(150)
    OP_43(0x11, 0x0, 0x0, 0x6)

    def lambda_1D05():
        OP_6C(110000, 2500)
        ExitThread()

    QueueWorkItem(0xD, 2, lambda_1D05)
    Sleep(1100)
    OP_44(0xD, 0x0)
    OP_44(0xE, 0x0)
    OP_44(0xF, 0x0)
    OP_44(0x10, 0x0)
    OP_44(0x11, 0x0)
    SetChrPos(0x101, 4270, 12000, 59160, 0)
    SetChrPos(0x105, 1920, 12000, 58210, 0)
    SetChrPos(0x103, 10, 12000, 59190, 0)
    Sleep(3000)
    OP_4F(0x1C, (scpexpr(EXPR_PUSH_LONG, 0x0), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))

    def lambda_1D6F():
        OP_6D(2090, 12000, 65720, 2000)
        ExitThread()

    QueueWorkItem(0x101, 3, lambda_1D6F)

    def lambda_1D87():
        OP_6B(2840, 2000)
        ExitThread()

    QueueWorkItem(0x101, 0, lambda_1D87)

    def lambda_1D97():
        OP_6C(129000, 2000)
        ExitThread()

    QueueWorkItem(0xD, 2, lambda_1D97)
    WaitChrThread(0x101, 0x3)

    ChrTalk(
        0x101,
        "#005F#3P什么！？\x02",
    )

    CloseMessageWindow()
    OP_51(0x101, 0x8, (scpexpr(EXPR_PUSH_LONG, 0x0), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0x101, 65535)

    def lambda_1DD2():
        OP_8E(0xFE, 0xEEC, 0x2EE0, 0x1064E, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_1DD2)

    ChrTalk(
        0x103,
        "#024F#3P来、来真的！？\x02",
    )

    CloseMessageWindow()
    Sleep(200)
    OP_51(0x103, 0x8, (scpexpr(EXPR_PUSH_LONG, 0x0), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0x103, 65535)

    def lambda_1E1E():
        OP_8E(0xFE, 0x2EE, 0x2EE0, 0x106DA, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x103, 1, lambda_1E1E)
    Sleep(500)
    OP_51(0x105, 0x8, (scpexpr(EXPR_PUSH_LONG, 0x0), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0x105, 65535)

    def lambda_1E4E():
        OP_8E(0xFE, 0x6EA, 0x2EE0, 0xED4E, 0xBB8, 0x0)
        ExitThread()

    QueueWorkItem(0x105, 1, lambda_1E4E)
    WaitChrThread(0x105, 0x1)

    def lambda_1E6E():
        TurnDirection(0xFE, 0x105, 400)
        ExitThread()

    QueueWorkItem(0x8, 1, lambda_1E6E)
    WaitChrThread(0x101, 0x1)

    ChrTalk(
        0x101,
        (
            "#580F不、不见了……\x02\x03",
            "跳到湖里去了……？\x02",
        )
    )

    CloseMessageWindow()
    WaitChrThread(0x103, 0x1)

    ChrTalk(
        0x103,
        (
            "#022F尽管真的跳了下去……\x01",
            "但是，湖面并没有任何波痕啊……\x02\x03",
            "那个男人，究竟是……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        (
            "#043F祖母大人……\x01",
            "您没有受伤吧！？\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#090F#6P我很好，科洛蒂娅。\x01",
            "他由始至终都没有伤害过我。\x02\x03",
            "#094F而且……\x02",
        )
    )

    CloseMessageWindow()
    ClearChrFlags(0xB, 0x80)
    ClearChrFlags(0xA, 0x80)
    ClearChrFlags(0xC, 0x80)
    ClearChrFlags(0x9, 0x80)
    SetChrFlags(0xB, 0x40)
    SetChrFlags(0xA, 0x40)
    SetChrFlags(0xC, 0x40)
    SetChrFlags(0x9, 0x40)
    SetChrPos(0xB, 1870, 12000, 45230, 0)
    SetChrPos(0xA, 1870, 12000, 45230, 0)
    SetChrPos(0xC, 1870, 12000, 45230, 0)
    SetChrPos(0x9, 1870, 12000, 45230, 0)
    OP_9F(0xA, 0xFF, 0xFF, 0xFF, 0x0, 0x0)
    OP_9F(0xB, 0xFF, 0xFF, 0xFF, 0x0, 0x0)
    OP_9F(0xC, 0xFF, 0xFF, 0xFF, 0x0, 0x0)
    OP_9F(0x9, 0xFF, 0xFF, 0xFF, 0x0, 0x0)

    NpcTalk(
        0xA,
        "少年的声音",
        "#3P艾丝蒂尔！\x02",
    )

    CloseMessageWindow()
    OP_1D(0x11)

    def lambda_2031():
        TurnDirection(0xFE, 0xA, 400)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_2031)

    def lambda_203F():
        TurnDirection(0xFE, 0xA, 400)
        ExitThread()

    QueueWorkItem(0x103, 1, lambda_203F)

    def lambda_204D():
        TurnDirection(0xFE, 0xA, 400)
        ExitThread()

    QueueWorkItem(0x105, 1, lambda_204D)

    def lambda_205B():
        OP_6D(2540, 12000, 61390, 2000)
        ExitThread()

    QueueWorkItem(0x101, 2, lambda_205B)

    def lambda_2073():
        OP_67(0, 9350, -10000, 4000)
        ExitThread()

    QueueWorkItem(0x101, 0, lambda_2073)

    def lambda_208B():
        OP_6B(2500, 4000)
        ExitThread()

    QueueWorkItem(0xD, 2, lambda_208B)
    OP_43(0xD, 0x1, 0x0, 0x3)
    SetChrChipByIndex(0xA, 23)

    def lambda_20A7():
        OP_9F(0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F4)
        ExitThread()

    QueueWorkItem(0xA, 2, lambda_20A7)

    def lambda_20B9():
        OP_8E(0xFE, 0xD2A, 0x2EE0, 0xE394, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0xA, 1, lambda_20B9)
    Sleep(500)
    SetChrChipByIndex(0x9, 26)

    def lambda_20DE():
        OP_9F(0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F4)
        ExitThread()

    QueueWorkItem(0x9, 2, lambda_20DE)

    def lambda_20F0():
        OP_8E(0xFE, 0x7D0, 0x2EE0, 0xE876, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x9, 1, lambda_20F0)
    Sleep(500)
    SetChrChipByIndex(0xB, 24)

    def lambda_2115():

        label("loc_2115")

        TurnDirection(0xFE, 0x101, 0)
        OP_48()
        Jump("loc_2115")

    QueueWorkItem2(0xB, 1, lambda_2115)

    def lambda_2126():
        OP_9F(0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F4)
        ExitThread()

    QueueWorkItem(0xB, 2, lambda_2126)

    def lambda_2138():
        OP_8E(0xFE, 0x816, 0x2EE0, 0xE204, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0xB, 3, lambda_2138)
    Sleep(500)
    SetChrChipByIndex(0xC, 25)

    def lambda_215D():

        label("loc_215D")

        TurnDirection(0xFE, 0x101, 0)
        OP_48()
        Jump("loc_215D")

    QueueWorkItem2(0xC, 1, lambda_215D)

    def lambda_216E():
        OP_9F(0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F4)
        ExitThread()

    QueueWorkItem(0xC, 2, lambda_216E)

    def lambda_2180():
        OP_8E(0xFE, 0x2C6, 0x2EE0, 0xE448, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0xC, 3, lambda_2180)

    def lambda_219B():
        OP_8E(0xFE, 0xDF2, 0x2EE0, 0xE826, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_219B)
    Sleep(500)

    def lambda_21BB():
        OP_8E(0xFE, 0x96, 0x2EE0, 0xEBB4, 0x1388, 0x0)
        ExitThread()

    QueueWorkItem(0x103, 1, lambda_21BB)

    def lambda_21D6():
        OP_6D(2140, 12000, 59300, 2000)
        ExitThread()

    QueueWorkItem(0x101, 2, lambda_21D6)

    def lambda_21EE():
        OP_6E(307, 2000)
        ExitThread()

    QueueWorkItem(0x101, 3, lambda_21EE)
    SetChrFlags(0x105, 0x40)
    OP_8E(0x105, 0xB22, 0x2EE0, 0xF000, 0x7D0, 0x0)
    TurnDirection(0x105, 0x9, 400)
    WaitChrThread(0x103, 0x1)

    def lambda_2223():
        TurnDirection(0xFE, 0xA, 400)
        ExitThread()

    QueueWorkItem(0x103, 1, lambda_2223)
    WaitChrThread(0x101, 0x0)

    ChrTalk(
        0x101,
        (
            "#004F约修亚！？\x02\x03",
            "#001F太好了，你平安无事！\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xA,
        (
            "#010F#2P艾丝蒂尔你这边也是……\x02\x03",
            "因为上校和少尉都没有在城内，\x01",
            "所以我很担心你们这里的情况。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#505F那个戴红色头盔的洛伦斯少尉\x01",
            "倒是刚才还在这里……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xA,
        "#014F#2P咦……！？\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x103,
        (
            "#522F那个男人从栏杆那里一跃而下，\x01",
            "已经逃得无影无踪了。\x02\x03",
            "#025F简直是个超乎常人的怪物啊……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xA,
        (
            "#013F#2P哦，原来是这样啊……\x02\x03",
            "#015F总之，大家能平安无事……\x01",
            "这已经是最好的结局了……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        "#008F约修亚……\x02",
    )

    CloseMessageWindow()
    SetChrChipByIndex(0x9, 1)
    OP_8E(0x9, 0x730, 0x2EE0, 0xEBD2, 0x7D0, 0x0)

    ChrTalk(
        0x9,
        "#171F#2P陛下……幸好您没事……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#091F尤莉亚中尉……\x01",
            "能再见到你我真的很高兴呢。\x02\x03",
            "#090F而且，各位朋友……\x01",
            "我对你们的感激也是一言难尽啊。\x02",
        )
    )

    CloseMessageWindow()

    def lambda_248E():
        TurnDirection(0xFE, 0x8, 400)
        ExitThread()

    QueueWorkItem(0x101, 1, lambda_248E)

    def lambda_249C():
        TurnDirection(0xFE, 0x8, 400)
        ExitThread()

    QueueWorkItem(0x103, 1, lambda_249C)

    def lambda_24AA():
        TurnDirection(0xFE, 0x8, 400)
        ExitThread()

    QueueWorkItem(0x105, 1, lambda_24AA)

    def lambda_24B8():
        TurnDirection(0xFE, 0x8, 400)
        ExitThread()

    QueueWorkItem(0xA, 1, lambda_24B8)

    def lambda_24C6():
        TurnDirection(0xFE, 0x8, 400)
        ExitThread()

    QueueWorkItem(0xB, 1, lambda_24C6)

    def lambda_24D4():
        TurnDirection(0xFE, 0x8, 400)
        ExitThread()

    QueueWorkItem(0xC, 1, lambda_24D4)

    ChrTalk(
        0xB,
        (
            "#031F#2P呵呵，女王陛下。\x01",
            "非常荣幸能得到您的赞美之词。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xC,
        (
            "#070F#2P能够为您效劳，我已深感荣幸了。\x02\x03",
            "#074F不过现在还没有到结束的时候。\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x9,
        (
            "#175F#2P虽然我们已经镇压了城内的特务兵，\x01",
            "但是，又传来了不利的消息。\x02\x03",
            "各地的正规军部队正朝着王都方向攻来……\x01",
            "　\x02\x03",
            "他们很可能是被情报部给操控了。\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        "#093F是这样吗……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x9,
        (
            "#178F#2P虽然很抱歉，不过已经没时间了。\x02\x03",
            "陛下，请您乘坐飞艇从这里离开吧。\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#094F不行……我办不到。\x02\x03",
            "#092F因为更为严重的是……\x01",
            "一场可怕的灾难可能就要发生了。\x02\x03",
            "所以，当务之急……\x01",
            "无论如何也要阻止理查德上校。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x9,
        "#173F#2P怎、怎么回事呢？\x02",
    )

    CloseMessageWindow()
    Sleep(100)
    OP_20(0x3E8)
    Fade(1000)
    OP_6D(2200, 12000, 60780, 0)
    OP_67(0, 6870, -10000, 0)
    OP_6B(2650, 0)
    OP_6C(45000, 0)
    OP_6E(280, 0)
    SetChrPos(0x105, 3190, 12000, 60950, 270)
    OP_21()
    OP_0D()
    OP_1D(0x21)
    Sleep(500)

    ChrTalk(
        0x8,
        (
            "#093F昨夜，我和上校长谈了一番，\x01",
            "终于明白他发动政变的真正目的。\x02\x03",
            "他好像企图把『辉之环』据为己有。\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#004F『辉之环』……\x02\x03",
            "好、好像在哪听说过这个东西……\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xA,
        (
            "#015F#2P那是空之女神赐予古代人的\x01",
            "『七至宝』之一……\x02\x03",
            "#012F可以支配世间一切的传说中的古代遗物。\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#505F哦，是亚鲁瓦教授说过的……\x02\x03",
            "可那只是教会流传下来的故事啊。\x01",
            "　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        "#094F………………………………\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        "#580F啊……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0xB,
        (
            "#032F嗯，应该存在吧？\x02\x03",
            "在这个利贝尔王国的某处。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#093F王室中也有这么一个古老的传说。\x02\x03",
            "#094F『辉之环，总有一天会带来灾难，\x01",
            "　将人类之子的灵魂与炼狱相接。』\x02\x03",
            "『吾等，为了作为人而存在，\x01",
            "　将其封印在昏暗的狭间……』\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xC,
        (
            "#074F『将人类之子的灵魂与炼狱相接』……\x02\x03",
            "#072F实在是……令人感到可怕的说法啊。　　\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#092F这些箴言……\x01",
            "作为戒律由代代的国王相传至今。\x02\x03",
            "那个被称作『辉之环』的物品\x01",
            "恐怕具有相当的危险性，\x01",
            "因此，王家的先祖们将其封印了起来。  \x02\x03",
            "而且，以前在王都的地下\x01",
            "还检测出了巨大的导力反应……\x02\x03",
            "如果把这两者结合起来考虑的话……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0xA,
        (
            "#012F#2P那么就可以推断出……\x01",
            "　\x02\x03",
            "王都的地下封印着『辉之环』吧。\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#093F是啊……\x01",
            "上校肯定也是这么推断的。\x02\x03",
            "『辉之环』究竟是什么样的东西，\x01",
            "这一点并没有被传承下来……\x02\x03",
            "一旦该物品被人唤醒，\x01",
            "说不定会发生十分可怕的事情。\x02\x03",
            "也许，甚至能和过去所发生的\x01",
            "传说中的『大崩坏』匹敌……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        "#043F怎、怎么会这样……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x103,
        "#522F没有想到，竟然会……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x101,
        (
            "#002F女王陛下！\x02\x03",
            "那个洛伦斯少尉刚才说过\x01",
            "『前往地下去吧』之类的话……\x02\x03",
            "那是代表什么意思呢？\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x8,
        (
            "#094F在这个格兰赛尔城里有\x01",
            "一间奇怪的房间……\x02\x03",
            "是一个什么东西也不保管、\x01",
            "而且从很久以前就禁止入内的地方……\x02",
        )
    )

    CloseMessageWindow()

    ChrTalk(
        0x105,
        "#044F啊……\x02",
    )

    CloseMessageWindow()

    ChrTalk(
        0x9,
        "#172F是宝物库吧！？\x02",
    )

    CloseMessageWindow()
    FadeToDark(1500, 0, -1)
    OP_0D()
    OP_28(0x4E, 0x1, 0x40)
    OP_28(0x4E, 0x1, 0x80)
    OP_28(0x4E, 0x1, 0x100)
    OP_28(0x4E, 0x1, 0x200)
    OP_28(0x4E, 0x1, 0x400)
    OP_28(0x4F, 0x4, 0x2)
    OP_28(0x4F, 0x4, 0x4)
    SetMapFlags(0x2000000)
    OP_A2(0x3FB)
    NewScene("ED6_DT01/T4240   ._SN", 100, 0, 0)
    IdleLoop()
    Return()

    # Function_2_35D end

    def Function_3_2DA6(): pass

    label("Function_3_2DA6")

    WaitChrThread(0xA, 0x1)
    SetChrChipByIndex(0xA, 2)
    WaitChrThread(0x9, 0x1)
    SetChrSubChip(0x9, 1)
    SetChrChipByIndex(0x9, 27)
    WaitChrThread(0xB, 0x3)
    SetChrChipByIndex(0xB, 3)
    WaitChrThread(0xC, 0x3)
    SetChrChipByIndex(0xC, 4)
    Return()

    # Function_3_2DA6 end

    def Function_4_2DD4(): pass

    label("Function_4_2DD4")

    SetChrFlags(0xFE, 0x40)
    SetChrFlags(0xFE, 0x20)
    SetChrFlags(0xFE, 0x4)
    ClearChrFlags(0xFE, 0x80)
    OP_96(0xFE, 0x83E, 0x2EE0, 0xEB28, 0x190, 0x1770)
    SetChrChipByIndex(0xFE, 6)

    def lambda_2E0A():
        OP_99(0xFE, 0x0, 0x1, 0x7D0)
        ExitThread()

    QueueWorkItem(0xFE, 3, lambda_2E0A)
    OP_96(0xFE, 0x79E, 0x3A98, 0xE6AA, 0xBB8, 0x1F40)
    OP_A2(0x0)
    ClearChrFlags(0xFE, 0x400)
    Sleep(500)
    OP_A2(0x1)

    def lambda_2E41():
        OP_99(0xFE, 0x2, 0x5, 0x7D0)
        ExitThread()

    QueueWorkItem(0xFE, 3, lambda_2E41)
    OP_96(0xFE, 0x744, 0x2EE0, 0xE204, 0x0, 0x3A98)
    OP_A2(0x2)
    Sleep(2000)

    def lambda_2E70():
        OP_99(0xFE, 0x3, 0xB, 0xFA0)
        ExitThread()

    QueueWorkItem(0xFE, 3, lambda_2E70)
    Return()

    # Function_4_2DD4 end

    def Function_5_2E7B(): pass

    label("Function_5_2E7B")

    SetChrFlags(0xFE, 0x40)
    SetChrFlags(0xFE, 0x20)
    SetChrFlags(0xFE, 0x4)
    ClearChrFlags(0xFE, 0x80)
    OP_96(0xFE, 0x83E, 0x2EE0, 0xEB28, 0x190, 0x1770)
    SetChrChipByIndex(0xFE, 6)

    def lambda_2EB1():
        OP_99(0xFE, 0x0, 0x1, 0x7D0)
        ExitThread()

    QueueWorkItem(0xFE, 3, lambda_2EB1)
    OP_22(0xA3, 0x0, 0x64)
    OP_96(0xFE, 0x79E, 0x3A98, 0xE6AA, 0xBB8, 0x1F40)
    OP_A2(0x0)
    ClearChrFlags(0xFE, 0x400)
    Sleep(500)
    OP_A2(0x1)

    def lambda_2EED():
        OP_99(0xFE, 0x2, 0x5, 0x7D0)
        ExitThread()

    QueueWorkItem(0xFE, 3, lambda_2EED)
    OP_96(0xFE, 0x744, 0x2EE0, 0xE204, 0x0, 0x3A98)
    OP_A2(0x2)
    Sleep(2000)

    def lambda_2F1C():
        OP_99(0xFE, 0x3, 0xB, 0xFA0)
        ExitThread()

    QueueWorkItem(0xFE, 3, lambda_2F1C)
    Return()

    # Function_5_2E7B end

    def Function_6_2F27(): pass

    label("Function_6_2F27")

    SetChrFlags(0xFE, 0x40)
    SetChrFlags(0xFE, 0x4)
    ClearChrFlags(0xFE, 0x20)
    SetChrChipByIndex(0xFE, 19)
    OP_8E(0xFE, 0x992, 0x2EE0, 0xF622, 0x1770, 0x0)
    OP_8E(0xFE, 0x762, 0x2EE0, 0xFE60, 0x1770, 0x0)
    OP_96(0xFE, 0x7F8, 0x3066, 0x10888, 0x320, 0xDAC)
    OP_4F(0x1C, (scpexpr(EXPR_PUSH_LONG, 0x1), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0xFE, 20)
    ClearChrFlags(0xFE, 0x80)

    def lambda_2F93():
        OP_9F(0xFE, 0xFF, 0xFF, 0xFF, 0x0, 0x5DC)
        ExitThread()

    QueueWorkItem(0xFE, 1, lambda_2F93)
    OP_96(0xFE, 0x73A, 0x1194, 0x132A4, 0x3E8, 0xFA0)
    Return()

    # Function_6_2F27 end

    def Function_7_2FB7(): pass

    label("Function_7_2FB7")

    SetChrFlags(0xFE, 0x40)
    SetChrFlags(0xFE, 0x4)
    ClearChrFlags(0xFE, 0x20)
    SetChrChipByIndex(0xFE, 19)
    OP_8E(0xFE, 0x992, 0x2EE0, 0xF622, 0x1770, 0x0)
    OP_8E(0xFE, 0x762, 0x2EE0, 0xFE60, 0x1770, 0x0)
    OP_22(0xA4, 0x0, 0x64)
    OP_96(0xFE, 0x7F8, 0x3066, 0x10888, 0x320, 0xDAC)
    OP_4F(0x1C, (scpexpr(EXPR_PUSH_LONG, 0x1), scpexpr(EXPR_STUB), scpexpr(EXPR_END)))
    SetChrChipByIndex(0xFE, 20)
    ClearChrFlags(0xFE, 0x80)

    def lambda_3028():
        OP_9F(0xFE, 0xFF, 0xFF, 0xFF, 0x0, 0x5DC)
        ExitThread()

    QueueWorkItem(0xFE, 1, lambda_3028)
    OP_22(0xA3, 0x0, 0x64)
    OP_22(0x99, 0x0, 0x64)
    OP_96(0xFE, 0x73A, 0x1194, 0x132A4, 0x3E8, 0xFA0)
    Return()

    # Function_7_2FB7 end

    SaveToFile()

Try(main)
