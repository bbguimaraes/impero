#ifndef IMPERO_CMD_COMMAND_H
#define IMPERO_CMD_COMMAND_H

#include <concepts>
#include <string>
#include <type_traits>

namespace impero {

struct Command {
    using Result = bool;
    virtual Result execute() const = 0;
};

template<typename T>
concept CommandExecutor = std::is_convertible_v<
    std::invoke_result_t<T, std::string_view>,
    Command::Result>;

template<CommandExecutor auto F>
class ExecCommand : public Command {
    std::string m_command;
public:
    ExecCommand(std::string command) : m_command(std::move(command)) {}
    std::string_view command() const { return this->m_command; }
    Result execute() const override { return F(this->m_command); }
};

}

#endif
