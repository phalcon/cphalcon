<?php

class ParamsTask extends \Phalcon\CLI\Task
{
    public function paramsAction($params)
    {
        return ($params === $this->dispatcher->getParams())
                ? '$params is the same as $this->dispatcher->getParams()'
                : '$params is not the same as $this->dispatcher->getParams()';
    }

    public function paramAction($params)
    {
        return ($params[0] === $this->dispatcher->getParam(0))
                ? '$param[0] is the same as $this->dispatcher->getParam(0)'
                : '$param[0] is not the same as $this->dispatcher->getParam(0)';
    }
}
