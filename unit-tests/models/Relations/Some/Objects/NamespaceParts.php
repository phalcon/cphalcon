<?php
namespace Some\Objects;

class NamespaceParts extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany('id', 'Some\\Service\\NamespaceRobotsParts', 'parts_id');
	}

	public function getSource()
	{
		return 'parts';
	}

}