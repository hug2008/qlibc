#include <errno.h>
 * @param options         combination of options.
 * @note
 *   Available options:
 *   - QLOG_OPT_THREADSAFE - make it thread-safe.
 *   - QLOG_OPT_FLUSH -  flush out buffer everytime.
 *
 *   qlog_t *log = qlog("/tmp/qdecoder-%Y%m%d.err", 0644, 86400, QLOG_OPT_THREADSAFE);
qlog_t *qlog(const char *filepathfmt, mode_t mode, int rotateinterval, int options)
    // malloc qlog_t structure
    log = (qlog_t *)calloc(1, sizeof(qlog_t));
    if (log == NULL) {
        errno = ENOMEM;
        return NULL;
    }
    // set up the structure.
    // handle options
    if (options & QLOG_OPT_THREADSAFE) {
        Q_MUTEX_NEW(log->qmutex, true);
        if (log->qmutex == NULL) {
            errno = ENOMEM;
            free(log);
            return NULL;
        }
    }
    if (options & QLOG_OPT_FLUSH) {
        log->logflush = true;
    }

    // try to open the log file.
        Q_MUTEX_DESTROY(log->qmutex);
    /* check if log rotation is needed */