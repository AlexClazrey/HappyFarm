#include "Farm.h"
#include "FarmCommand.h"

Farm::Farm()
{
}

Farm::~Farm()
{
}

int Farm::executeCommand(FarmCommand* cmd) {
    int y = cmd->toYard(&yard),
        f = cmd->toField(),
        p = cmd->toPack(&pack),
        m = cmd->toMoney(&money);
    return y | f | p | m;
}
