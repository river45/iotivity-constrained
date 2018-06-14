#ifndef CONFIG_H
#define CONFIG_H

/* Time resolution */
#include <stdint.h>
#include <time.h>
typedef uint64_t oc_clock_time_t;
#define OC_CLOCK_CONF_TICKS_PER_SECOND CLOCKS_PER_SEC

#if defined(OC_IPV4) && __ANDROID_API__ < 24
/* Warning: Android has often over 10 interfaces. */
#define OC_MAX_NUM_INTERFACES 20
#endif /* OC_IPV4 */

/* Security Layer */
/* Max inactivity timeout before tearing down DTLS connection */
#define OC_DTLS_INACTIVITY_TIMEOUT (600)

/* If we selected support for dynamic memory allocation */
#ifdef OC_DYNAMIC_ALLOCATION
#define OC_COLLECTIONS
#define OC_BLOCK_WISE

#else /* OC_DYNAMIC_ALLOCATION */
/* List of constraints below for a build that does not employ dynamic
   memory allocation
*/
/* Memory pool sizes */
#define OC_BYTES_POOL_SIZE (1800)
#define OC_INTS_POOL_SIZE (100)
#define OC_DOUBLES_POOL_SIZE (4)

/* Server-side parameters */
/* Maximum number of server resources */
#define OC_MAX_APP_RESOURCES (4)

#define OC_MAX_NUM_COLLECTIONS (1)

/* Common paramters */
/* Prescriptive lower layers MTU size, enable block-wise transfers */
#define OC_BLOCK_WISE_SET_MTU (700)

/* Maximum size of request/response payloads */
#define OC_MAX_APP_DATA_SIZE (2048)

/* Maximum number of concurrent requests */
#define OC_MAX_NUM_CONCURRENT_REQUESTS (3)

/* Maximum number of nodes in a payload tree structure */
#define OC_MAX_NUM_REP_OBJECTS (150)

/* Number of devices on the OCF platform */
#define OC_MAX_NUM_DEVICES (2)

/* Maximum number of endpoints */
#define OC_MAX_NUM_ENDPOINTS (20)

/* Security layer */
/* Maximum number of authorized clients */
#define OC_MAX_NUM_SUBJECTS (2)

/* Maximum number of concurrent (D)TLS sessions */
#define OC_MAX_TLS_PEERS (1)

/* Maximum number of peer for TCP channel */
#define OC_MAX_TCP_PEERS (2)

/* Maximum number of interfaces for IP adapter */
/* Warning: Android has often over 10 interfaces. */
#define OC_MAX_IP_INTERFACES (20)

/* Maximum number of callbacks for Network interface event monitoring */
#define OC_MAX_NETWORK_INTERFACE_CBS (2)

/* Maximum number of callbacks for connection of session */
#define OC_MAX_SESSION_EVENT_CBS (2)

#endif /* !OC_DYNAMIC_ALLOCATION */

#endif /* CONFIG_H */