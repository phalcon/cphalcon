<?php

class Parts2 extends \Phalcon\Mvc\Model
{
	public function initialize()
	{
		$eventsManager = new \Phalcon\Events\Manager();

		$eventsManager->attach('model', function($event, $robot) {  return true; });
		$this->setEventsManager($eventsManager);
		$this->setSource('parts');
	}
}
