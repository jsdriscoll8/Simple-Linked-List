#include "warmup.jsdrisco.h"
#include <stdlib.h>
#include <string.h>

Thing *createThing(char *name, unsigned int weight){
    Thing *t = malloc(sizeof(Thing));

    // If name is not null and within boundaries, and weight > 0, continue and return new Thing
    if(name != NULL && strlen(name) > 0 && strlen(name) <= MAX_NAME_LENGTH && weight > 0){
        strcpy(t->name, name);
        t->weight = weight;
        return t;
    }
    // Otherwise, return null
    else
        return NULL;
}

int compareThings(Thing *thingOne, Thing *thingTwo){
    // If thingOne's name comes lexicographically before thing2, return -1
    // If after, return 1
    // If the same, refer to weight values by the same method
    // If both values are identical, return 0
    if(strcmp(thingOne->name, thingTwo->name) < 0)
        return -1;
    else if(strcmp(thingOne->name, thingTwo->name) > 0)
        return 1;
    else {
        if(thingOne->weight > thingTwo->weight)
            return 1;
        else if(thingOne->weight < thingTwo->weight)
            return -1;
        else
            return 0;
    }
}