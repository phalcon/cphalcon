<?php

namespace Phalcon\Test\Models\Relations;

use Phalcon\Mvc\Model;

/**
 * Phalcon\Test\Models\Relations\RelationsParts
 *
 * @package Phalcon\Test\Models\Relations
 */
class RelationsParts extends Model
{
	public function initialize()
	{
		$this->hasMany(
		    'id',
            RelationsRobotsParts::class,
            'parts_id',
            ['foreignKey' => ['message' => 'Parts cannot be deleted because is referenced by a Robot']]
        );
	}

	public function getSource()
	{
		return 'parts';
	}
}
