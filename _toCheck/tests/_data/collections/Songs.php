<?php

namespace Phalcon\Test\Collections;

use Phalcon\Mvc\Collection;

/**
 * Songs Collection
 *
 * @method static Songs[] find(array $parameters = null)
 * @method static Songs findFirst(array $parameters = null)
 *
 * @property \MongoId _id
 * @property string artist
 * @property string name
 *
 * @package Phalcon\Test\Collections
 */
class Songs extends Collection
{
}
