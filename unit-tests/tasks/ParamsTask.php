<?php

class ParamsTask extends \Phalcon\CLI\Task
{
	public function paramsAction($params)
	{
		return ($params === $this->dispatcher->getParams())
				? 'same'
				: 'not same';
	}

	public function paramAction($params)
	{
		return ($params[0] === $this->dispatcher->getParam(0))
				? 'same'
				: 'not same';
	}
}
