<?php

namespace Phalcon\Test\Fixtures\Modules\Backend\Tasks;

class MainTask extends \Phalcon\CLI\Task
{
    public function throwAction()
    {
        throw new \Exception('Task Run');
    }

    public function noopAction()
    {
        return;
    }
}
