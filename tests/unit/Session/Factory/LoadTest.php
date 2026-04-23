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

namespace Phalcon\Tests\Unit\Session\Factory;

use Phalcon\Tests\AbstractUnitTestCase;

final class LoadTest extends AbstractUnitTestCase
{
    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testSessionFactoryLoadArray(): void
    {
        $this->markTestSkipped('Phalcon\\Session\\Factory does not exist in cphalcon');
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testSessionFactoryLoadConfig(): void
    {
        $this->markTestSkipped('Phalcon\\Session\\Factory does not exist in cphalcon');
    }
}
