<?php

class FailureController extends ControllerBase
{
	public function exceptionAction()
	{
		throw new \Exception('failure by exception');
	}
}
