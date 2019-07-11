#ifndef DC_EVENT_H
#define DC_EVENT_H

#include <stdint.h>
#include <jansson.h>

struct dc_event_;
typedef struct dc_event_ *dc_event_t;

typedef enum {
    DC_EVENT_TYPE_UNKNOWN = 0,
    DC_EVENT_TYPE_READY,
    DC_EVENT_TYPE_MESSAGE_CREATE,

    /* ^^^^^^ Make sure events are up there ^^^^^^^ */
    DC_EVENT_TYPE_LAST,
} dc_event_type_t;

dc_event_t dc_event_new(char const *type, json_t *payload);

/**
 * Returns the event type. This is an upper case string, with
 * words separated by underscores. For a list of available event
 * types please see the Discord documentation.
 */
char const *dc_event_type(dc_event_t e);

/**
 * The JSON payload associated with the given event type. Note this
 * could be json_null() if the event has no associated payload.
 */
json_t *dc_event_payload(dc_event_t e);

/**
 * Returns an integer code representing the given type string.
 */
dc_event_type_t dc_event_type_code(dc_event_t e);

#endif