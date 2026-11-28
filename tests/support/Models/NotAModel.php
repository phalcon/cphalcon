<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Models;

/**
 * A class that is not a model, used as the target of a relation.
 *
 * It has a constructor: Manager::load() of a class with no constructor
 * crashes cphalcon (phalcon/cphalcon#17754).
 */
class NotAModel
{
    public function __construct(
        mixed $data = null,
        mixed $container = null,
        mixed $manager = null
    ) {
    }
}
