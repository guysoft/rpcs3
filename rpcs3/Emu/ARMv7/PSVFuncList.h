#pragma once
#include "ARMv7Thread.h"
#include "Emu/SysCalls/LogBase.h"

class psv_log_base : public LogBase
{
	std::string m_name;

public:
	psv_log_base(const std::string& name)
		: m_name(name)
	{
	}

	virtual const std::string& GetName() const override
	{
		return m_name;
	}

};

enum psv_error_codes
{
	SCE_OK = 0,

	SCE_ERROR_ERRNO_EPERM				 = 0x80010001,
	SCE_ERROR_ERRNO_ENOENT				 = 0x80010002,
	SCE_ERROR_ERRNO_ESRCH				 = 0x80010003,
	SCE_ERROR_ERRNO_EINTR				 = 0x80010004,
	SCE_ERROR_ERRNO_EIO					 = 0x80010005,
	SCE_ERROR_ERRNO_ENXIO				 = 0x80010006,
	SCE_ERROR_ERRNO_E2BIG				 = 0x80010007,
	SCE_ERROR_ERRNO_ENOEXEC				 = 0x80010008,
	SCE_ERROR_ERRNO_EBADF				 = 0x80010009,
	SCE_ERROR_ERRNO_ECHILD				 = 0x8001000A,
	SCE_ERROR_ERRNO_EAGAIN				 = 0x8001000B,
	SCE_ERROR_ERRNO_ENOMEM				 = 0x8001000C,
	SCE_ERROR_ERRNO_EACCES				 = 0x8001000D,
	SCE_ERROR_ERRNO_EFAULT				 = 0x8001000E,
	SCE_ERROR_ERRNO_ENOTBLK				 = 0x8001000F,
	SCE_ERROR_ERRNO_EBUSY				 = 0x80010010,
	SCE_ERROR_ERRNO_EEXIST				 = 0x80010011,
	SCE_ERROR_ERRNO_EXDEV				 = 0x80010012,
	SCE_ERROR_ERRNO_ENODEV				 = 0x80010013,
	SCE_ERROR_ERRNO_ENOTDIR				 = 0x80010014,
	SCE_ERROR_ERRNO_EISDIR				 = 0x80010015,
	SCE_ERROR_ERRNO_EINVAL				 = 0x80010016,
	SCE_ERROR_ERRNO_ENFILE				 = 0x80010017,
	SCE_ERROR_ERRNO_EMFILE				 = 0x80010018,
	SCE_ERROR_ERRNO_ENOTTY				 = 0x80010019,
	SCE_ERROR_ERRNO_ETXTBSY				 = 0x8001001A,
	SCE_ERROR_ERRNO_EFBIG				 = 0x8001001B,
	SCE_ERROR_ERRNO_ENOSPC				 = 0x8001001C,
	SCE_ERROR_ERRNO_ESPIPE				 = 0x8001001D,
	SCE_ERROR_ERRNO_EROFS				 = 0x8001001E,
	SCE_ERROR_ERRNO_EMLINK				 = 0x8001001F,
	SCE_ERROR_ERRNO_EPIPE				 = 0x80010020,
	SCE_ERROR_ERRNO_EDOM				 = 0x80010021,
	SCE_ERROR_ERRNO_ERANGE				 = 0x80010022,
	SCE_ERROR_ERRNO_ENOMSG				 = 0x80010023,
	SCE_ERROR_ERRNO_EIDRM				 = 0x80010024,
	SCE_ERROR_ERRNO_ECHRNG				 = 0x80010025,
	SCE_ERROR_ERRNO_EL2NSYNC			 = 0x80010026,
	SCE_ERROR_ERRNO_EL3HLT				 = 0x80010027,
	SCE_ERROR_ERRNO_EL3RST				 = 0x80010028,
	SCE_ERROR_ERRNO_ELNRNG				 = 0x80010029,
	SCE_ERROR_ERRNO_EUNATCH				 = 0x8001002A,
	SCE_ERROR_ERRNO_ENOCSI				 = 0x8001002B,
	SCE_ERROR_ERRNO_EL2HLT				 = 0x8001002C,
	SCE_ERROR_ERRNO_EDEADLK				 = 0x8001002D,
	SCE_ERROR_ERRNO_ENOLCK				 = 0x8001002E,
	SCE_ERROR_ERRNO_EFORMAT				 = 0x8001002F,
	SCE_ERROR_ERRNO_EUNSUP				 = 0x80010030,
	SCE_ERROR_ERRNO_EBADE				 = 0x80010032,
	SCE_ERROR_ERRNO_EBADR				 = 0x80010033,
	SCE_ERROR_ERRNO_EXFULL				 = 0x80010034,
	SCE_ERROR_ERRNO_ENOANO				 = 0x80010035,
	SCE_ERROR_ERRNO_EBADRQC				 = 0x80010036,
	SCE_ERROR_ERRNO_EBADSLT				 = 0x80010037,
	SCE_ERROR_ERRNO_EDEADLOCK			 = 0x80010038,
	SCE_ERROR_ERRNO_EBFONT				 = 0x80010039,
	SCE_ERROR_ERRNO_ENOSTR				 = 0x8001003C,
	SCE_ERROR_ERRNO_ENODATA				 = 0x8001003D,
	SCE_ERROR_ERRNO_ETIME				 = 0x8001003E,
	SCE_ERROR_ERRNO_ENOSR				 = 0x8001003F,
	SCE_ERROR_ERRNO_ENONET				 = 0x80010040,
	SCE_ERROR_ERRNO_ENOPKG				 = 0x80010041,
	SCE_ERROR_ERRNO_EREMOTE				 = 0x80010042,
	SCE_ERROR_ERRNO_ENOLINK				 = 0x80010043,
	SCE_ERROR_ERRNO_EADV				 = 0x80010044,
	SCE_ERROR_ERRNO_ESRMNT				 = 0x80010045,
	SCE_ERROR_ERRNO_ECOMM				 = 0x80010046,
	SCE_ERROR_ERRNO_EPROTO				 = 0x80010047,
	SCE_ERROR_ERRNO_EMULTIHOP			 = 0x8001004A,
	SCE_ERROR_ERRNO_ELBIN				 = 0x8001004B,
	SCE_ERROR_ERRNO_EDOTDOT				 = 0x8001004C,
	SCE_ERROR_ERRNO_EBADMSG				 = 0x8001004D,
	SCE_ERROR_ERRNO_EFTYPE				 = 0x8001004F,
	SCE_ERROR_ERRNO_ENOTUNIQ			 = 0x80010050,
	SCE_ERROR_ERRNO_EBADFD				 = 0x80010051,
	SCE_ERROR_ERRNO_EREMCHG				 = 0x80010052,
	SCE_ERROR_ERRNO_ELIBACC				 = 0x80010053,
	SCE_ERROR_ERRNO_ELIBBAD				 = 0x80010054,
	SCE_ERROR_ERRNO_ELIBSCN				 = 0x80010055,
	SCE_ERROR_ERRNO_ELIBMAX				 = 0x80010056,
	SCE_ERROR_ERRNO_ELIBEXEC			 = 0x80010057,
	SCE_ERROR_ERRNO_ENOSYS				 = 0x80010058,
	SCE_ERROR_ERRNO_ENMFILE				 = 0x80010059,
	SCE_ERROR_ERRNO_ENOTEMPTY			 = 0x8001005A,
	SCE_ERROR_ERRNO_ENAMETOOLONG		 = 0x8001005B,
	SCE_ERROR_ERRNO_ELOOP				 = 0x8001005C,
	SCE_ERROR_ERRNO_EOPNOTSUPP			 = 0x8001005F,
	SCE_ERROR_ERRNO_EPFNOSUPPORT		 = 0x80010060,
	SCE_ERROR_ERRNO_ECONNRESET			 = 0x80010068,
	SCE_ERROR_ERRNO_ENOBUFS				 = 0x80010069,
	SCE_ERROR_ERRNO_EAFNOSUPPORT		 = 0x8001006A,
	SCE_ERROR_ERRNO_EPROTOTYPE			 = 0x8001006B,
	SCE_ERROR_ERRNO_ENOTSOCK			 = 0x8001006C,
	SCE_ERROR_ERRNO_ENOPROTOOPT			 = 0x8001006D,
	SCE_ERROR_ERRNO_ESHUTDOWN			 = 0x8001006E,
	SCE_ERROR_ERRNO_ECONNREFUSED		 = 0x8001006F,
	SCE_ERROR_ERRNO_EADDRINUSE			 = 0x80010070,
	SCE_ERROR_ERRNO_ECONNABORTED		 = 0x80010071,
	SCE_ERROR_ERRNO_ENETUNREACH			 = 0x80010072,
	SCE_ERROR_ERRNO_ENETDOWN			 = 0x80010073,
	SCE_ERROR_ERRNO_ETIMEDOUT			 = 0x80010074,
	SCE_ERROR_ERRNO_EHOSTDOWN			 = 0x80010075,
	SCE_ERROR_ERRNO_EHOSTUNREACH		 = 0x80010076,
	SCE_ERROR_ERRNO_EINPROGRESS			 = 0x80010077,
	SCE_ERROR_ERRNO_EALREADY			 = 0x80010078,
	SCE_ERROR_ERRNO_EDESTADDRREQ		 = 0x80010079,
	SCE_ERROR_ERRNO_EMSGSIZE			 = 0x8001007A,
	SCE_ERROR_ERRNO_EPROTONOSUPPORT		 = 0x8001007B,
	SCE_ERROR_ERRNO_ESOCKTNOSUPPORT		 = 0x8001007C,
	SCE_ERROR_ERRNO_EADDRNOTAVAIL		 = 0x8001007D,
	SCE_ERROR_ERRNO_ENETRESET			 = 0x8001007E,
	SCE_ERROR_ERRNO_EISCONN				 = 0x8001007F,
	SCE_ERROR_ERRNO_ENOTCONN			 = 0x80010080,
	SCE_ERROR_ERRNO_ETOOMANYREFS		 = 0x80010081,
	SCE_ERROR_ERRNO_EPROCLIM			 = 0x80010082,
	SCE_ERROR_ERRNO_EUSERS				 = 0x80010083,
	SCE_ERROR_ERRNO_EDQUOT				 = 0x80010084,
	SCE_ERROR_ERRNO_ESTALE				 = 0x80010085,
	SCE_ERROR_ERRNO_ENOTSUP				 = 0x80010086,
	SCE_ERROR_ERRNO_ENOMEDIUM			 = 0x80010087,
	SCE_ERROR_ERRNO_ENOSHARE			 = 0x80010088,
	SCE_ERROR_ERRNO_ECASECLASH			 = 0x80010089,
	SCE_ERROR_ERRNO_EILSEQ				 = 0x8001008A,
	SCE_ERROR_ERRNO_EOVERFLOW			 = 0x8001008B,
	SCE_ERROR_ERRNO_ECANCELED			 = 0x8001008C,
	SCE_ERROR_ERRNO_ENOTRECOVERABLE		 = 0x8001008D,
	SCE_ERROR_ERRNO_EOWNERDEAD			 = 0x8001008E,

	SCE_KERNEL_ERROR_ERROR				 = 0x80020001,
	SCE_KERNEL_ERROR_NOT_IMPLEMENTED	 = 0x80020002,
	SCE_KERNEL_ERROR_INVALID_ARGUMENT	 = 0x80020003,
	SCE_KERNEL_ERROR_INVALID_ARGUMENT_SIZE = 0x80020004,
	SCE_KERNEL_ERROR_INVALID_FLAGS		 = 0x80020005,
	SCE_KERNEL_ERROR_ILLEGAL_SIZE		 = 0x80020006,
	SCE_KERNEL_ERROR_ILLEGAL_ADDR		 = 0x80020007,
	SCE_KERNEL_ERROR_UNSUP				 = 0x80020008,
	SCE_KERNEL_ERROR_ILLEGAL_MODE		 = 0x80020009,
	SCE_KERNEL_ERROR_ILLEGAL_ALIGNMENT	 = 0x8002000A,
	SCE_KERNEL_ERROR_NOSYS				 = 0x8002000B,
	SCE_KERNEL_ERROR_DEBUG_ERROR		 = 0x80021000,
	SCE_KERNEL_ERROR_ILLEGAL_DIPSW_NUMBER = 0x80021001,
	SCE_KERNEL_ERROR_CPU_ERROR			 = 0x80022000,
	SCE_KERNEL_ERROR_MMU_ILLEGAL_L1_TYPE = 0x80022001,
	SCE_KERNEL_ERROR_MMU_L2_INDEX_OVERFLOW = 0x80022002,
	SCE_KERNEL_ERROR_MMU_L2_SIZE_OVERFLOW = 0x80022003,
	SCE_KERNEL_ERROR_INVALID_CPU_AFFINITY = 0x80022004,
	SCE_KERNEL_ERROR_INVALID_MEMORY_ACCESS = 0x80022005,
	SCE_KERNEL_ERROR_INVALID_MEMORY_ACCESS_PERMISSION = 0x80022006,
	SCE_KERNEL_ERROR_VA2PA_FAULT		 = 0x80022007,
	SCE_KERNEL_ERROR_VA2PA_MAPPED		 = 0x80022008,
	SCE_KERNEL_ERROR_VALIDATION_CHECK_FAILED = 0x80022009,
	SCE_KERNEL_ERROR_SYSMEM_ERROR		 = 0x80024000,
	SCE_KERNEL_ERROR_INVALID_PROCESS_CONTEXT = 0x80024001,
	SCE_KERNEL_ERROR_UID_NAME_TOO_LONG	 = 0x80024002,
	SCE_KERNEL_ERROR_VARANGE_IS_NOT_PHYSICAL_CONTINUOUS = 0x80024003,
	SCE_KERNEL_ERROR_PHYADDR_ERROR		 = 0x80024100,
	SCE_KERNEL_ERROR_NO_PHYADDR			 = 0x80024101,
	SCE_KERNEL_ERROR_PHYADDR_USED		 = 0x80024102,
	SCE_KERNEL_ERROR_PHYADDR_NOT_USED	 = 0x80024103,
	SCE_KERNEL_ERROR_NO_IOADDR			 = 0x80024104,
	SCE_KERNEL_ERROR_PHYMEM_ERROR		 = 0x80024300,
	SCE_KERNEL_ERROR_ILLEGAL_PHYPAGE_STATUS = 0x80024301,
	SCE_KERNEL_ERROR_NO_FREE_PHYSICAL_PAGE = 0x80024302,
	SCE_KERNEL_ERROR_NO_FREE_PHYSICAL_PAGE_UNIT = 0x80024303,
	SCE_KERNEL_ERROR_PHYMEMPART_NOT_EMPTY = 0x80024304,
	SCE_KERNEL_ERROR_NO_PHYMEMPART_LPDDR2 = 0x80024305,
	SCE_KERNEL_ERROR_NO_PHYMEMPART_CDRAM = 0x80024306,
	SCE_KERNEL_ERROR_FIXEDHEAP_ERROR	 = 0x80024400,
	SCE_KERNEL_ERROR_FIXEDHEAP_ILLEGAL_SIZE = 0x80024401,
	SCE_KERNEL_ERROR_FIXEDHEAP_ILLEGAL_INDEX = 0x80024402,
	SCE_KERNEL_ERROR_FIXEDHEAP_INDEX_OVERFLOW = 0x80024403,
	SCE_KERNEL_ERROR_FIXEDHEAP_NO_CHUNK	 = 0x80024404,
	SCE_KERNEL_ERROR_UID_ERROR			 = 0x80024500,
	SCE_KERNEL_ERROR_INVALID_UID		 = 0x80024501,
	SCE_KERNEL_ERROR_SYSMEM_UID_INVALID_ARGUMENT = 0x80024502,
	SCE_KERNEL_ERROR_SYSMEM_INVALID_UID_RANGE = 0x80024503,
	SCE_KERNEL_ERROR_SYSMEM_NO_VALID_UID = 0x80024504,
	SCE_KERNEL_ERROR_SYSMEM_CANNOT_ALLOCATE_UIDENTRY = 0x80024505,
	SCE_KERNEL_ERROR_NOT_PROCESS_UID	 = 0x80024506,
	SCE_KERNEL_ERROR_NOT_KERNEL_UID		 = 0x80024507,
	SCE_KERNEL_ERROR_INVALID_UID_CLASS	 = 0x80024508,
	SCE_KERNEL_ERROR_INVALID_UID_SUBCLASS = 0x80024509,
	SCE_KERNEL_ERROR_UID_CANNOT_FIND_BY_NAME = 0x8002450A,
	SCE_KERNEL_ERROR_VIRPAGE_ERROR		 = 0x80024600,
	SCE_KERNEL_ERROR_ILLEGAL_VIRPAGE_TYPE = 0x80024601,
	SCE_KERNEL_ERROR_BLOCK_ERROR		 = 0x80024700,
	SCE_KERNEL_ERROR_ILLEGAL_BLOCK_ID	 = 0x80024701,
	SCE_KERNEL_ERROR_ILLEGAL_BLOCK_TYPE	 = 0x80024702,
	SCE_KERNEL_ERROR_BLOCK_IN_USE		 = 0x80024703,
	SCE_KERNEL_ERROR_PARTITION_ERROR	 = 0x80024800,
	SCE_KERNEL_ERROR_ILLEGAL_PARTITION_ID = 0x80024801,
	SCE_KERNEL_ERROR_ILLEGAL_PARTITION_INDEX = 0x80024802,
	SCE_KERNEL_ERROR_NO_L2PAGETABLE		 = 0x80024803,
	SCE_KERNEL_ERROR_HEAPLIB_ERROR		 = 0x80024900,
	SCE_KERNEL_ERROR_ILLEGAL_HEAP_ID	 = 0x80024901,
	SCE_KERNEL_ERROR_OUT_OF_RANG		 = 0x80024902,
	SCE_KERNEL_ERROR_HEAPLIB_NOMEM		 = 0x80024903,
	SCE_KERNEL_ERROR_SYSMEM_ADDRESS_SPACE_ERROR = 0x80024A00,
	SCE_KERNEL_ERROR_INVALID_ADDRESS_SPACE_ID = 0x80024A01,
	SCE_KERNEL_ERROR_INVALID_PARTITION_INDEX = 0x80024A02,
	SCE_KERNEL_ERROR_ADDRESS_SPACE_CANNOT_FIND_PARTITION_BY_ADDR = 0x80024A03,
	SCE_KERNEL_ERROR_SYSMEM_MEMBLOCK_ERROR = 0x80024B00,
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK_TYPE = 0x80024B01,
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK_REMAP_TYPE = 0x80024B02,
	SCE_KERNEL_ERROR_NOT_PHY_CONT_MEMBLOCK = 0x80024B03,
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK_CODE = 0x80024B04,
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK_SIZE = 0x80024B05,
	SCE_KERNEL_ERROR_ILLEGAL_USERMAP_SIZE = 0x80024B06,
	SCE_KERNEL_ERROR_MEMBLOCK_TYPE_FOR_KERNEL_PROCESS = 0x80024B07,
	SCE_KERNEL_ERROR_PROCESS_CANNOT_REMAP_MEMBLOCK = 0x80024B08,
	SCE_KERNEL_ERROR_SYSMEM_PHYMEMLOW_ERROR = 0x80024C00,
	SCE_KERNEL_ERROR_CANNOT_ALLOC_PHYMEMLOW = 0x80024C01,
	SCE_KERNEL_ERROR_UNKNOWN_PHYMEMLOW_TYPE = 0x80024C02,
	SCE_KERNEL_ERROR_SYSMEM_BITHEAP_ERROR = 0x80024D00,
	SCE_KERNEL_ERROR_CANNOT_ALLOC_BITHEAP = 0x80024D01,
	SCE_KERNEL_ERROR_LOADCORE_ERROR		 = 0x80025000,
	SCE_KERNEL_ERROR_ILLEGAL_ELF_HEADER	 = 0x80025001,
	SCE_KERNEL_ERROR_ILLEGAL_SELF_HEADER = 0x80025002,
	SCE_KERNEL_ERROR_EXCPMGR_ERROR		 = 0x80027000,
	SCE_KERNEL_ERROR_ILLEGAL_EXCPCODE	 = 0x80027001,
	SCE_KERNEL_ERROR_ILLEGAL_EXCPHANDLER = 0x80027002,
	SCE_KERNEL_ERROR_NOTFOUND_EXCPHANDLER = 0x80027003,
	SCE_KERNEL_ERROR_CANNOT_RELEASE_EXCPHANDLER = 0x80027004,
	SCE_KERNEL_ERROR_INTRMGR_ERROR		 = 0x80027100,
	SCE_KERNEL_ERROR_ILLEGAL_CONTEXT	 = 0x80027101,
	SCE_KERNEL_ERROR_ILLEGAL_INTRCODE	 = 0x80027102,
	SCE_KERNEL_ERROR_ILLEGAL_INTRPARAM	 = 0x80027103,
	SCE_KERNEL_ERROR_ILLEGAL_INTRPRIORITY = 0x80027104,
	SCE_KERNEL_ERROR_ILLEGAL_TARGET_CPU	 = 0x80027105,
	SCE_KERNEL_ERROR_ILLEGAL_INTRFILTER	 = 0x80027106,
	SCE_KERNEL_ERROR_ILLEGAL_INTRTYPE	 = 0x80027107,
	SCE_KERNEL_ERROR_ILLEGAL_HANDLER	 = 0x80027108,
	SCE_KERNEL_ERROR_FOUND_HANDLER		 = 0x80027109,
	SCE_KERNEL_ERROR_NOTFOUND_HANDLER	 = 0x8002710A,
	SCE_KERNEL_ERROR_NO_MEMORY			 = 0x8002710B,
	SCE_KERNEL_ERROR_DMACMGR_ERROR		 = 0x80027200,
	SCE_KERNEL_ERROR_ALREADY_QUEUED		 = 0x80027201,
	SCE_KERNEL_ERROR_NOT_QUEUED			 = 0x80027202,
	SCE_KERNEL_ERROR_NOT_SETUP			 = 0x80027203,
	SCE_KERNEL_ERROR_ON_TRANSFERRING	 = 0x80027204,
	SCE_KERNEL_ERROR_NOT_INITIALIZED	 = 0x80027205,
	SCE_KERNEL_ERROR_TRANSFERRED		 = 0x80027206,
	SCE_KERNEL_ERROR_NOT_UNDER_CONTROL	 = 0x80027207,
	SCE_KERNEL_ERROR_SYSTIMER_ERROR		 = 0x80027300,
	SCE_KERNEL_ERROR_NO_FREE_TIMER		 = 0x80027301,
	SCE_KERNEL_ERROR_TIMER_NOT_ALLOCATED = 0x80027302,
	SCE_KERNEL_ERROR_TIMER_COUNTING		 = 0x80027303,
	SCE_KERNEL_ERROR_TIMER_STOPPED		 = 0x80027304,
	SCE_KERNEL_ERROR_THREADMGR_ERROR	 = 0x80028000,
	SCE_KERNEL_ERROR_DORMANT			 = 0x80028001,
	SCE_KERNEL_ERROR_NOT_DORMANT		 = 0x80028002,
	SCE_KERNEL_ERROR_UNKNOWN_THID		 = 0x80028003,
	SCE_KERNEL_ERROR_CAN_NOT_WAIT		 = 0x80028004,
	SCE_KERNEL_ERROR_ILLEGAL_THID		 = 0x80028005,
	SCE_KERNEL_ERROR_THREAD_TERMINATED	 = 0x80028006,
	SCE_KERNEL_ERROR_DELETED			 = 0x80028007,
	SCE_KERNEL_ERROR_WAIT_TIMEOUT		 = 0x80028008,
	SCE_KERNEL_ERROR_NOTIFY_CALLBACK	 = 0x80028009,
	SCE_KERNEL_ERROR_WAIT_DELETE		 = 0x8002800A,
	SCE_KERNEL_ERROR_ILLEGAL_ATTR		 = 0x8002800B,
	SCE_KERNEL_ERROR_EVF_MULTI			 = 0x8002800C,
	SCE_KERNEL_ERROR_WAIT_CANCEL		 = 0x8002800D,
	SCE_KERNEL_ERROR_EVF_COND			 = 0x8002800E,
	SCE_KERNEL_ERROR_ILLEGAL_COUNT		 = 0x8002800F,
	SCE_KERNEL_ERROR_ILLEGAL_PRIORITY	 = 0x80028010,
	SCE_KERNEL_ERROR_MUTEX_RECURSIVE	 = 0x80028011,
	SCE_KERNEL_ERROR_MUTEX_LOCK_OVF		 = 0x80028012,
	SCE_KERNEL_ERROR_MUTEX_NOT_OWNED	 = 0x80028013,
	SCE_KERNEL_ERROR_MUTEX_UNLOCK_UDF	 = 0x80028014,
	SCE_KERNEL_ERROR_MUTEX_FAILED_TO_OWN = 0x80028015,
	SCE_KERNEL_ERROR_FAST_MUTEX_RECURSIVE = 0x80028016,
	SCE_KERNEL_ERROR_FAST_MUTEX_LOCK_OVF = 0x80028017,
	SCE_KERNEL_ERROR_FAST_MUTEX_FAILED_TO_OWN = 0x80028018,
	SCE_KERNEL_ERROR_FAST_MUTEX_NOT_OWNED = 0x80028019,
	SCE_KERNEL_ERROR_FAST_MUTEX_OWNED	 = 0x8002801A,
	SCE_KERNEL_ERROR_ALARM_CAN_NOT_CANCEL = 0x8002801B,
	SCE_KERNEL_ERROR_INVALID_OBJECT_TYPE = 0x8002801C,
	SCE_KERNEL_ERROR_KERNEL_TLS_FULL	 = 0x8002801D,
	SCE_KERNEL_ERROR_ILLEGAL_KERNEL_TLS_INDEX = 0x8002801E,
	SCE_KERNEL_ERROR_KERNEL_TLS_BUSY	 = 0x8002801F,
	SCE_KERNEL_ERROR_DIFFERENT_UID_CLASS = 0x80028020,
	SCE_KERNEL_ERROR_UNKNOWN_UID		 = 0x80028021,
	SCE_KERNEL_ERROR_SEMA_ZERO			 = 0x80028022,
	SCE_KERNEL_ERROR_SEMA_OVF			 = 0x80028023,
	SCE_KERNEL_ERROR_PMON_NOT_THREAD_MODE = 0x80028024,
	SCE_KERNEL_ERROR_PMON_NOT_CPU_MODE	 = 0x80028025,
	SCE_KERNEL_ERROR_ALREADY_REGISTERED	 = 0x80028026,
	SCE_KERNEL_ERROR_INVALID_THREAD_ID	 = 0x80028027,
	SCE_KERNEL_ERROR_ALREADY_DEBUG_SUSPENDED = 0x80028028,
	SCE_KERNEL_ERROR_NOT_DEBUG_SUSPENDED = 0x80028029,
	SCE_KERNEL_ERROR_CAN_NOT_USE_VFP	 = 0x8002802A,
	SCE_KERNEL_ERROR_RUNNING			 = 0x8002802B,
	SCE_KERNEL_ERROR_EVENT_COND			 = 0x8002802C,
	SCE_KERNEL_ERROR_MSG_PIPE_FULL		 = 0x8002802D,
	SCE_KERNEL_ERROR_MSG_PIPE_EMPTY		 = 0x8002802E,
	SCE_KERNEL_ERROR_ALREADY_SENT		 = 0x8002802F,
	SCE_KERNEL_ERROR_CAN_NOT_SUSPEND	 = 0x80028030,
	SCE_KERNEL_ERROR_FAST_MUTEX_ALREADY_INITIALIZED = 0x80028031,
	SCE_KERNEL_ERROR_FAST_MUTEX_NOT_INITIALIZED = 0x80028032,
	SCE_KERNEL_ERROR_THREAD_STOPPED		 = 0x80028033,
	SCE_KERNEL_ERROR_THREAD_SUSPENDED	 = 0x80028034,
	SCE_KERNEL_ERROR_NOT_SUSPENDED		 = 0x80028035,
	SCE_KERNEL_ERROR_WAIT_DELETE_MUTEX	 = 0x80028036,
	SCE_KERNEL_ERROR_WAIT_CANCEL_MUTEX	 = 0x80028037,
	SCE_KERNEL_ERROR_WAIT_DELETE_COND	 = 0x80028038,
	SCE_KERNEL_ERROR_WAIT_CANCEL_COND	 = 0x80028039,
	SCE_KERNEL_ERROR_LW_MUTEX_NOT_OWNED	 = 0x8002803A,
	SCE_KERNEL_ERROR_LW_MUTEX_LOCK_OVF	 = 0x8002803B,
	SCE_KERNEL_ERROR_LW_MUTEX_UNLOCK_UDF = 0x8002803C,
	SCE_KERNEL_ERROR_LW_MUTEX_RECURSIVE	 = 0x8002803D,
	SCE_KERNEL_ERROR_LW_MUTEX_FAILED_TO_OWN = 0x8002803E,
	SCE_KERNEL_ERROR_WAIT_DELETE_LW_MUTEX = 0x8002803F,
	SCE_KERNEL_ERROR_ILLEGAL_STACK_SIZE	 = 0x80028040,
	SCE_KERNEL_ERROR_RW_LOCK_RECURSIVE = 0x80028041,
	SCE_KERNEL_ERROR_RW_LOCK_LOCK_OVF	 = 0x80028042,
	SCE_KERNEL_ERROR_RW_LOCK_NOT_OWNED = 0x80028043,
	SCE_KERNEL_ERROR_RW_LOCK_UNLOCK_UDF	 = 0x80028044,
	SCE_KERNEL_ERROR_RW_LOCK_FAILED_TO_LOCK = 0x80028045,
	SCE_KERNEL_ERROR_RW_LOCK_FAILED_TO_UNLOCK = 0x80028046,

	SCE_KERNEL_ERROR_PROCESSMGR_ERROR	 = 0x80029000,
	SCE_KERNEL_ERROR_INVALID_PID		 = 0x80029001,
	SCE_KERNEL_ERROR_INVALID_PROCESS_TYPE = 0x80029002,
	SCE_KERNEL_ERROR_PLS_FULL			 = 0x80029003,
	SCE_KERNEL_ERROR_INVALID_PROCESS_STATUS = 0x80029004,
	SCE_KERNEL_ERROR_INVALID_BUDGET_ID	 = 0x80029005,
	SCE_KERNEL_ERROR_INVALID_BUDGET_SIZE = 0x80029006,
	SCE_KERNEL_ERROR_CP14_DISABLED		 = 0x80029007,
	SCE_KERNEL_ERROR_EXCEEDED_MAX_PROCESSES = 0x80029008,
	SCE_KERNEL_ERROR_PROCESS_REMAINING	 = 0x80029009,
	SCE_KERNEL_ERROR_IOFILEMGR_ERROR	 = 0x8002A000,
	SCE_KERNEL_ERROR_IO_NAME_TOO_LONG	 = 0x8002A001,
	SCE_KERNEL_ERROR_IO_REG_DEV			 = 0x8002A002,
	SCE_KERNEL_ERROR_IO_ALIAS_USED		 = 0x8002A003,
	SCE_KERNEL_ERROR_IO_DEL_DEV			 = 0x8002A004,
	SCE_KERNEL_ERROR_IO_WOULD_BLOCK		 = 0x8002A005,
	SCE_KERNEL_ERROR_MODULEMGR_START_FAILED = 0x8002D000,
	SCE_KERNEL_ERROR_MODULEMGR_STOP_FAIL = 0x8002D001,
	SCE_KERNEL_ERROR_MODULEMGR_IN_USE	 = 0x8002D002,
	SCE_KERNEL_ERROR_MODULEMGR_NO_LIB	 = 0x8002D003,
	SCE_KERNEL_ERROR_MODULEMGR_SYSCALL_REG = 0x8002D004,
	SCE_KERNEL_ERROR_MODULEMGR_NOMEM_LIB = 0x8002D005,
	SCE_KERNEL_ERROR_MODULEMGR_NOMEM_STUB = 0x8002D006,
	SCE_KERNEL_ERROR_MODULEMGR_NOMEM_SELF = 0x8002D007,
	SCE_KERNEL_ERROR_MODULEMGR_NOMEM	 = 0x8002D008,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_LIB = 0x8002D009,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_STUB = 0x8002D00A,
	SCE_KERNEL_ERROR_MODULEMGR_NO_FUNC_NID = 0x8002D00B,
	SCE_KERNEL_ERROR_MODULEMGR_NO_VAR_NID = 0x8002D00C,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_TYPE = 0x8002D00D,
	SCE_KERNEL_ERROR_MODULEMGR_NO_MOD_ENTRY = 0x8002D00E,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_PROC_PARAM = 0x8002D00F,
	SCE_KERNEL_ERROR_MODULEMGR_NO_MODOBJ = 0x8002D010,
	SCE_KERNEL_ERROR_MODULEMGR_NO_MOD	 = 0x8002D011,
	SCE_KERNEL_ERROR_MODULEMGR_NO_PROCESS = 0x8002D012,
	SCE_KERNEL_ERROR_MODULEMGR_OLD_LIB	 = 0x8002D013,
	SCE_KERNEL_ERROR_MODULEMGR_STARTED	 = 0x8002D014,
	SCE_KERNEL_ERROR_MODULEMGR_NOT_STARTED = 0x8002D015,
	SCE_KERNEL_ERROR_MODULEMGR_NOT_STOPPED = 0x8002D016,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_PROCESS_UID = 0x8002D017,
	SCE_KERNEL_ERROR_MODULEMGR_CANNOT_EXPORT_LIB_TO_SHARED = 0x8002D018,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_REL_INFO = 0x8002D019,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_REF_INFO = 0x8002D01A,
	SCE_KERNEL_ERROR_MODULEMGR_ELINK	 = 0x8002D01B,
	SCE_KERNEL_ERROR_MODULEMGR_NOENT	 = 0x8002D01C,
	SCE_KERNEL_ERROR_MODULEMGR_BUSY		 = 0x8002D01D,
	SCE_KERNEL_ERROR_MODULEMGR_NOEXEC	 = 0x8002D01E,
	SCE_KERNEL_ERROR_MODULEMGR_NAMETOOLONG = 0x8002D01F,
	SCE_KERNEL_ERROR_LIBRARYDB_NOENT	 = 0x8002D080,
	SCE_KERNEL_ERROR_LIBRARYDB_NO_LIB	 = 0x8002D081,
	SCE_KERNEL_ERROR_LIBRARYDB_NO_MOD	 = 0x8002D082,
	SCE_KERNEL_ERROR_AUTHFAIL			 = 0x8002F000,
	SCE_KERNEL_ERROR_NO_AUTH			 = 0x8002F001,
};

class psv_func_caller
{
public:
	virtual void operator()(ARMv7Thread& CPU) = 0;
	virtual ~psv_func_caller(){};
};

namespace psv_func_detail
{
	enum bind_arg_type
	{
		ARG_GENERAL,
		ARG_FLOAT,
		ARG_VECTOR,
		ARG_STACK,
	};

	template<typename T, bind_arg_type type, int g_count, int f_count, int v_count>
	struct bind_arg;

	template<typename T, int g_count, int f_count, int v_count>
	struct bind_arg<T, ARG_GENERAL, g_count, f_count, v_count>
	{
		static_assert(sizeof(T) <= 4, "Invalid function argument type for ARG_GENERAL");

		static __forceinline T func(ARMv7Thread& CPU)
		{
			return (T&)CPU.GPR[g_count - 1];
		}
	};

	template<typename T, int g_count, int f_count, int v_count>
	struct bind_arg<T, ARG_FLOAT, g_count, f_count, v_count>
	{
		static_assert(f_count <= 0, "TODO: Unsupported argument type (float)");
		static_assert(sizeof(T) <= 8, "Invalid function argument type for ARG_FLOAT");

		static __forceinline T func(ARMv7Thread& CPU)
		{
		}
	};

	template<typename T, int g_count, int f_count, int v_count>
	struct bind_arg<T, ARG_VECTOR, g_count, f_count, v_count>
	{
		static_assert(v_count <= 0, "TODO: Unsupported argument type (vector)");
		static_assert(sizeof(T) == 16, "Invalid function argument type for ARG_VECTOR");

		static __forceinline T func(ARMv7Thread& CPU)
		{
		}
	};

	template<typename T, int g_count, int f_count, int v_count>
	struct bind_arg<T, ARG_STACK, g_count, f_count, v_count>
	{
		static_assert(f_count <= 0, "TODO: Unsupported stack argument type (float)");
		static_assert(v_count <= 0, "TODO: Unsupported stack argument type (vector)");
		static_assert(sizeof(T) <= 4, "Invalid function argument type for ARG_STACK");

		static __forceinline T func(ARMv7Thread& CPU)
		{
			const u32 res = CPU.GetStackArg(g_count);
			return (T&)res;
		}
	};

	template<typename T, bind_arg_type type>
	struct bind_result
	{
		static_assert(type != ARG_FLOAT, "TODO: Unsupported funcion result type (float)");
		static_assert(type != ARG_VECTOR, "TODO: Unsupported funcion result type (vector)");
		static_assert(type == ARG_GENERAL, "Wrong use of bind_result template");
		static_assert(sizeof(T) <= 4, "Invalid function result type for ARG_GENERAL");

		static __forceinline void func(ARMv7Thread& CPU, T result)
		{
			CPU.GPR[0] = 0; // TODO
			(T&)CPU.GPR[0] = result;
		}
	};

	//template<typename T>
	//struct bind_result<T, ARG_FLOAT>
	//{
	//	static_assert(sizeof(T) <= 8, "Invalid function result type for ARG_FLOAT");

	//	static __forceinline void func(ARMv7Thread& CPU, T result)
	//	{
	//	}
	//};

	//template<typename T>
	//struct bind_result<T, ARG_VECTOR>
	//{
	//	static_assert(sizeof(T) == 16, "Invalid function result type for ARG_VECTOR");

	//	static __forceinline void func(ARMv7Thread& CPU, const T result)
	//	{
	//	}
	//};

	template <typename RT, typename F, typename Tuple, bool Done, int Total, int... N>
	struct call_impl
	{
		static __forceinline RT call(F f, Tuple && t)
		{
			return call_impl<RT, F, Tuple, Total == 1 + sizeof...(N), Total, N..., sizeof...(N)>::call(f, std::forward<Tuple>(t));
		}
	};

	template <typename RT, typename F, typename Tuple, int Total, int... N>
	struct call_impl<RT, F, Tuple, true, Total, N...>
	{
		static __forceinline RT call(F f, Tuple && t)
		{
			return f(std::get<N>(std::forward<Tuple>(t))...);
		}
	};

	template <typename RT, typename F, typename Tuple>
	__forceinline RT call(F f, Tuple && t)
	{
		typedef typename std::decay<Tuple>::type ttype;
		return psv_func_detail::call_impl<RT, F, Tuple, 0 == std::tuple_size<ttype>::value, std::tuple_size<ttype>::value>::call(f, std::forward<Tuple>(t));
	}

	template<int g_count, int f_count, int v_count>
	__forceinline std::tuple<> iterate(ARMv7Thread& CPU)
	{
		// terminator
		return std::tuple<>();
	}

	template<int g_count, int f_count, int v_count, typename T, typename... A>
	__forceinline std::tuple<T, A...> iterate(ARMv7Thread& CPU)
	{
		static_assert(!std::is_pointer<T>::value, "Invalid function argument type (pointer)");
		static_assert(!std::is_reference<T>::value, "Invalid function argument type (reference)");
		// TODO: check calculations
		const bool is_float = std::is_floating_point<T>::value;
		const bool is_vector = std::is_same<T, u128>::value;
		const bind_arg_type t = is_float
			? ((f_count >= 4) ? ARG_STACK : ARG_FLOAT)
			: (is_vector ? ((v_count >= 4) ? ARG_STACK : ARG_VECTOR) : ((g_count >= 4) ? ARG_STACK : ARG_GENERAL));
		const int g = g_count + (is_float || is_vector ? 0 : 1);
		const int f = f_count + (is_float ? 1 : 0);
		const int v = v_count + (is_vector ? 1 : 0);

		return std::tuple_cat(std::tuple<T>(bind_arg<T, t, g, f, v>::func(CPU)), iterate<g, f, v, A...>(CPU));
	}

	template<typename RT, typename... T>
	class func_binder;

	template<typename... T>
	class func_binder<void, T...> : public psv_func_caller
	{
		typedef void(*func_t)(T...);
		const func_t m_call;

	public:
		func_binder(func_t call)
			: psv_func_caller()
			, m_call(call)
		{
		}

		virtual void operator()(ARMv7Thread& CPU)
		{
			call<void>(m_call, iterate<0, 0, 0, T...>(CPU));
		}
	};

	template<typename... T>
	class func_binder<void, ARMv7Thread&, T...> : public psv_func_caller
	{
		typedef void(*func_t)(ARMv7Thread&, T...);
		const func_t m_call;

	public:
		func_binder(func_t call)
			: psv_func_caller()
			, m_call(call)
		{
		}

		virtual void operator()(ARMv7Thread& CPU)
		{
			call<void>(m_call, std::tuple_cat(std::tuple<ARMv7Thread&>(CPU), iterate<0, 0, 0, T...>(CPU)));
		}
	};

	template<typename RT, typename... T>
	class func_binder : public psv_func_caller
	{
		typedef RT(*func_t)(T...);
		const func_t m_call;

	public:
		func_binder(func_t call)
			: psv_func_caller()
			, m_call(call)
		{
		}

		virtual void operator()(ARMv7Thread& CPU)
		{
			static_assert(!std::is_pointer<RT>::value, "Invalid function result type (pointer)");
			static_assert(!std::is_reference<RT>::value, "Invalid function result type (reference)");
			const bool is_float = std::is_floating_point<RT>::value;
			const bool is_vector = std::is_same<RT, u128>::value;
			const bind_arg_type t = is_float ? ARG_FLOAT : (is_vector ? ARG_VECTOR : ARG_GENERAL);

			bind_result<RT, t>::func(CPU, call<RT>(m_call, iterate<0, 0, 0, T...>(CPU)));
		}
	};

	template<typename RT, typename... T>
	class func_binder<RT, ARMv7Thread&, T...> : public psv_func_caller
	{
		typedef RT(*func_t)(ARMv7Thread&, T...);
		const func_t m_call;

	public:
		func_binder(func_t call)
			: psv_func_caller()
			, m_call(call)
		{
		}

		virtual void operator()(ARMv7Thread& CPU)
		{
			static_assert(!std::is_pointer<RT>::value, "Invalid function result type (pointer)");
			static_assert(!std::is_reference<RT>::value, "Invalid function result type (reference)");
			const bool is_float = std::is_floating_point<RT>::value;
			const bool is_vector = std::is_same<RT, u128>::value;
			const bind_arg_type t = is_float ? ARG_FLOAT : (is_vector ? ARG_VECTOR : ARG_GENERAL);

			bind_result<RT, t>::func(CPU, call<RT>(m_call, std::tuple_cat(std::tuple<ARMv7Thread&>(CPU), iterate<0, 0, 0, T...>(CPU))));
		}
	};
}

struct psv_func
{
	u32 nid;
	const char* name;
	std::shared_ptr<psv_func_caller> func;
	psv_log_base* module;
};

void add_psv_func(psv_func& data);

template<typename RT, typename... T>
void reg_psv_func(u32 nid, psv_log_base* module, const char* name, RT(*func)(T...))
{
	psv_func f;
	f.nid = nid;
	f.name = name;
	f.func.reset(new psv_func_detail::func_binder<RT, T...>(func));
	f.module = module;

	add_psv_func(f);
}

psv_func* get_psv_func_by_nid(u32 nid);
u32 get_psv_func_index(psv_func* func);

void execute_psv_func_by_index(ARMv7Thread& CPU, u32 index);
void list_known_psv_modules();
