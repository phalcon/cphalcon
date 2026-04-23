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

namespace Phalcon\Tests\Unit\Session\Adapter;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Traits\SessionTrait;

final class OpenCloseTest extends AbstractUnitTestCase
{
    use DiTrait;
    use SessionTrait;

    /**
     * @dataProvider getClassNames
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testSessionAdapterClose(
        string $name
    ): void {
        $adapter = $this->newService($name);
        $actual  = $adapter->close();
        $this->assertTrue($actual);
    }

    /**
     * @dataProvider getClassNames
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testSessionAdapterOpen(
        string $name
    ): void {
        $adapter = $this->newService($name);
        $actual  = $adapter->open('test', 'test1');
        $this->assertTrue($actual);

        $actual = $adapter->close();
        $this->assertTrue($actual);
    }
}
