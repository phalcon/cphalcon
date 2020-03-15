<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Micro;

use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\MiddlewareInterface;

class MyMiddleware implements MiddlewareInterface
{
    /**
     * @var int
     */
    protected $number = 0;

    public function call(Micro $application)
    {
        $this->number++;
    }

    public function getNumber(): int
    {
        return $this->number;
    }
}
