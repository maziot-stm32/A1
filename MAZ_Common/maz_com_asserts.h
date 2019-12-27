/*
 * maz_com_asserts.h
 *
 *  Created on: 2019年12月27日
 *      Author: Paul
 */

#ifndef MAZ_COM_ASSERTS_H_
#define MAZ_COM_ASSERTS_H_

#define MAZASSERT_RETVAL(condition, ret, fmt, msg...)                   \
    if (condition)                                                      \
    {                                                                   \
        if (fmt)                                                        \
        {                                                               \
            debug_msg(fmt, ##msg);                                      \
        }                                                               \
        return ret;                                                     \
    }

#define MAZASSERT_RET(condition, fmt, msg...)                           \
    if (condition)                                                      \
    {                                                                   \
        if (fmt)                                                        \
        {                                                               \
            debug_msg(fmt, ##msg);                                      \
        }                                                               \
        return;                                                         \
    }

#define MAZASSERT_CTN(condition, fmt, msg...)                           \
    if (condition)                                                      \
    {                                                                   \
        if (fmt)                                                        \
        {                                                               \
            debug_msg(fmt, ##msg);                                      \
        }                                                               \
        continue;                                                       \
    }

#define MAZASSERT_BRK(condition, fmt, msg...)                           \
    if (condition)                                                      \
    {                                                                   \
        if (fmt)                                                        \
        {                                                               \
            debug_msg(fmt, ##msg);                                      \
        }                                                               \
        break;                                                          \
    }

#endif /* MAZ_COM_ASSERTS_H_ */
