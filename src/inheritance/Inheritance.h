#ifndef INHERITANCE_H
#define INHERITANCE_H

#pragma once

#include <string>

namespace organs {
    class Printable {
    public:
        virtual Printable *print() = 0;
    };

    class Organ : public Printable {
        std::string type;

    public:
        Organ( std::string type );
        virtual ~Organ();
        virtual Organ *print();
    };

    class Stomach : public Organ {
    public:
        Stomach();
        virtual ~Stomach();
    };

    class Brain : public Organ {
    public:
        Brain();
        virtual ~Brain();
        virtual Brain *print() override;
    };
}

#endif