// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file BigHelloWorld.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "BigHelloWorld.h"

#include <ucdr/microcdr.h>
#include <string.h>

bool BigHelloWorld_serialize_topic(
        ucdrBuffer* writer,
        const BigHelloWorld* topic)
{
    (void) ucdr_serialize_uint32_t(writer, topic->index);

    (void) ucdr_serialize_string(writer, topic->message);

    return !writer->error;
}

bool BigHelloWorld_deserialize_topic(
        ucdrBuffer* reader,
        BigHelloWorld* topic)
{
    (void) ucdr_deserialize_uint32_t(reader, &topic->index);

    (void) ucdr_deserialize_string(reader, topic->message, sizeof(topic->message));

    return !reader->error;
}

uint32_t BigHelloWorld_size_of_topic(
        const BigHelloWorld* topic,
        uint32_t size)
{
    uint32_t previousSize = size;
    size += (uint32_t)(ucdr_alignment(size, 4) + 4);

    size += (uint32_t)(ucdr_alignment(size, 4) + 4 + strlen(topic->message) + 1);

    return size - previousSize;
}
