/*
 * LaQueue
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"


void PQueue::push(void *item, int priority)
{
    node *newNode = new node;
    newNode->data = item;
    newNode->priority = priority;
    newNode->link = NULL;

    if(front == NULL || priority > front->priority)
    {
        newNode->link = front;
        front = newNode;
    }
    else
    {
        node *temp = front;

        while(temp->link != NULL && temp->link->priority >= priority)
        {
            temp = temp->link;
        }

        newNode->link = temp->link;
        temp->link = newNode;
    }
}



void* PQueue::top()
{
    if(front == NULL)
        return NULL;

    return front->data;
}


void PQueue::pop()
{
    if(front == NULL)
        return;

    node *temp = front;
    front = front->link;

    delete temp;
}


void PQueue::display()
{
    node *ptr = front;

    while(ptr != NULL)
    {
        std::cout << ptr->priority << " " << (char*)ptr->data << std::endl;
        ptr = ptr->link;
    }
}
