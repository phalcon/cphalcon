<?php
namespace Some\Service;

class NamespaceRobotsParts extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->belongsTo('parts_id', 'Some\\Objects\\NamespaceParts', 'id');
		$this->belongsTo('robots_id', 'Some\\Persons\\NamespaceRobots', 'id');
	}

	public function getSource()
	{
		return 'robots_parts';
	}

}