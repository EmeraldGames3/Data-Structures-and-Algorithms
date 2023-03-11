#ifndef EXAMPLE_H
#define EXAMPLE_H

class Example {
public:
    explicit Example(int value);

    void printValue() const;

private:
    int m_value;
};

#endif // EXAMPLE_H
