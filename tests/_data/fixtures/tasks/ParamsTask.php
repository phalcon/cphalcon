<?php

class ParamsTask extends \Phalcon\CLI\Task
{
    public function paramsAction()
    {
        return (func_get_args() === $this->dispatcher->getParams())
                ? 'Action params are the same as $this->dispatcher->getParams()'
                : 'Action params are not the same as $this->dispatcher->getParams()';
    }

    public function paramAction($param)
    {
        return ($param === $this->dispatcher->getParam(0))
                ? '$param[0] is the same as $this->dispatcher->getParam(0)'
                : '$param[0] is not the same as $this->dispatcher->getParam(0)';
    }
}
