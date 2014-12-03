<?php
namespace Some\Persons;

class NamespaceRobots extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
        $this->hasOne('id', 'Some\\Persons\\NamespaceRobots', 'id');
        $this->hasMany('id', 'Some\\Service\\NamespaceRobotsParts', 'robots_id');
		$this->hasManyToMany(
            'id', 'Some\\Service\\NamespaceRobotsParts', 'robots_id', 'parts_id', 'Some\\Objects\\NamespaceParts', 'id'
        );
	}

	public function getSource()
	{
		return 'robots';
	}

}