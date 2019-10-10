<?php
namespace Phalcon\Test\Fixtures\Tasks;

class EchoTask extends \Phalcon\Cli\Task
{
    public function mainAction()
    {
        return 'echoMainAction';
    }
}
