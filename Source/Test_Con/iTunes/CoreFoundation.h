ML_NAMESPACE_BEGIN(CF);

// run loop

enum
{
    kCFRunLoopRunFinished      = 1,
    kCFRunLoopRunStopped       = 2,
    kCFRunLoopRunTimedOut      = 3,
    kCFRunLoopRunHandledSource = 4,
};

DECL_SELECTANY
VOID
(CDECL
*CFRunLoopRun)(
    VOID
);

DECL_SELECTANY
VOID
(CDECL
*CFRunLoopRunInMode)(
    CFStringRef Mode,
    DOUBLE      Seconds,
    BOOL        ReturnAfterSourceHandled
);

DECL_SELECTANY CFRunLoopRef (CDECL *CFRunLoopGetCurrent)();
DECL_SELECTANY VOID (CDECL *CFRunLoopSourceInvalidate)(CFRunLoopSourceRef RunLoopSource);

DECL_SELECTANY
VOID
(CDECL
*CFRunLoopAddSource)(
    CFRunLoopRef        RunLoop,
    CFRunLoopSourceRef  LoopSource,
    CFStringRef         RunLoopMode
);

DECL_SELECTANY
VOID
(CDECL
*CFRunLoopRemoveSource)(
    CFRunLoopRef        RunLoop,
    CFRunLoopSourceRef  LoopSource,
    CFStringRef         RunLoopMode
);

// type

DECL_SELECTANY CFTypeID (CDECL *CFGetTypeID)(CFObjectRef Object);
DECL_SELECTANY CFTypeID (CDECL *CFStringGetTypeID)();
DECL_SELECTANY CFTypeID (CDECL *CFDictionaryGetTypeID)();


// data

DECL_SELECTANY
CFDataRef
(CDECL
*CFDataCreate)(
    CFAllocatorRef  Allocator,
    PVOID           Buffer,
    ULONG           Size
);

DECL_SELECTANY
CFDataRef
(CDECL
*CFPropertyListCreateXMLData)(
    CFAllocatorRef      Allocator,
    CFPropertyListRef   PropertyList
);

DECL_SELECTANY CFIndex  (CDECL *CFDataGetLength)(CFDataRef Data);
DECL_SELECTANY PBYTE    (CDECL *CFDataGetBytePtr)(CFDataRef Data);


// array

DECL_SELECTANY
CFArrayRef
(CDECL
*CFArrayCreate)(
    CFAllocatorRef  Allocator,
    PVOID*          Values,
    CFIndex         NumberOfValues,
    PVOID           Callbacks
);

DECL_SELECTANY
CFMutableArrayRef
(CDECL
*CFArrayCreateMutable)(
    CFAllocatorRef  Allocator,
    CFIndex         Capacity,
    PVOID           Callbacks
);


// string

DECL_SELECTANY
CFStringRef
(CDECL
*CFStringCreateWithCString)(
    CFAllocatorRef      Allocator,
    PCSTR               String,
    CFStringEncoding    Encoding
);

#define CFSTR(s) CFStringMakeConstantString(s)

DECL_SELECTANY CFStringRef (CDECL *CFStringMakeConstantString)(PCSTR String);
DECL_SELECTANY CFIndex  (CDECL *CFStringGetLength)(CFStringRef String);

DECL_SELECTANY
BOOL
(CDECL
*CFStringGetCString)(
    CFStringRef         String,
    PVOID               Buffer,
    CFIndex             BufferSize,
    CFStringEncoding    Encoding
);

DECL_SELECTANY
PVOID
(CDECL
*CFStringGetCStringPtr)(
    CFStringRef         String,
    CFStringEncoding    Encoding
);

// object

DECL_SELECTANY VOID (CDECL *CFRetain)(CFObjectRef Object);
DECL_SELECTANY VOID (CDECL *CFRelease)(CFObjectRef Object);


// boolean

DECL_SELECTANY PCFBooleanRef    kCFBooleanTrue;
DECL_SELECTANY PCFBooleanRef    kCFBooleanFalse;
DECL_SELECTANY CFStringRef*     kCFRunLoopDefaultMode;
DECL_SELECTANY CFStringRef*     kCFRunLoopCommonModes;

inline NTSTATUS Initialize()
{
    PVOID Module = LoadDll(L"CoreFoundation.dll");

    LOAD_INTERFACE(CFRunLoopRun);
    LOAD_INTERFACE(CFRunLoopRunInMode);
    LOAD_INTERFACE(CFRunLoopGetCurrent);
    LOAD_INTERFACE(CFRunLoopSourceInvalidate);
    LOAD_INTERFACE(CFRunLoopAddSource);
    LOAD_INTERFACE(CFRunLoopRemoveSource);

    LOAD_INTERFACE(CFPropertyListCreateXMLData);

    LOAD_INTERFACE(CFGetTypeID);
    LOAD_INTERFACE(CFStringGetTypeID);
    LOAD_INTERFACE(CFDictionaryGetTypeID);

    LOAD_INTERFACE(CFDataGetLength);
    LOAD_INTERFACE(CFDataGetBytePtr);

    LOAD_INTERFACE(CFArrayCreate);
    LOAD_INTERFACE(CFArrayCreateMutable);

    LOAD_INTERFACE(CFStringCreateWithCString);
    LOAD_INTERFACE_(CFStringMakeConstantString, "__CFStringMakeConstantString");
    LOAD_INTERFACE(CFStringGetCString);
    LOAD_INTERFACE(CFStringGetCStringPtr);
    LOAD_INTERFACE(CFStringGetLength);

    LOAD_INTERFACE(CFRetain);
    LOAD_INTERFACE(CFRelease);

    LOAD_INTERFACE(kCFBooleanTrue);
    LOAD_INTERFACE(kCFBooleanFalse);
    LOAD_INTERFACE(kCFRunLoopDefaultMode);
    LOAD_INTERFACE(kCFRunLoopCommonModes);

    return STATUS_SUCCESS;
}

ML_NAMESPACE_END_(CF);
