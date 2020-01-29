<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Service;

/**
 * Class HelloService
 */
class HelloService
{
    /**
     * @var int
     */
    private $count = 0;

    public function __invoke(string $name): string
    {
        $this->count = $this->count + 1;

        return "Hello {$name} [count: {$this->count}]";
    }
}
