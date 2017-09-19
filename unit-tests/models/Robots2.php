<?php

class Robots2 extends Phalcon\Mvc\Model
{
	protected $myname;

    public function getSource() {
        return 'robots';
    }

    public function getName() {
        return $this->myname;
    }

	public function columnMap() {
		return array(
			'id' => 'id',
			'name' => 'myname',
			'type' => 'type',
			'year' => 'year',
			'datetime' => 'datetime',
			'deleted' => 'deleted',
			'text' => 'text',
		);
	}
}
