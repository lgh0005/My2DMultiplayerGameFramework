#pragma once

template<typename T>
class SingletonBehaviour
{
public:
    static T& GetInstance() { static T s_Instance; return s_Instance; }
    SingletonBehaviour(const SingletonBehaviour&) = delete;
    SingletonBehaviour& operator=(const SingletonBehaviour&) = delete;

public:
    virtual void Init() {}
    virtual void Update() {}

protected:
    SingletonBehaviour() = default;
    virtual ~SingletonBehaviour() = default;
};