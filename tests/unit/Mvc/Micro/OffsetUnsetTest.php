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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Mvc\Micro;
use Phalcon\Tests\AbstractUnitTestCase;

class OffsetUnsetTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcMicroOffsetUnset(): void
    {
        $micro = new Micro();
        $di    = new Di();

        $micro->setDi($di);

        $escaper = new Escaper();

        $micro->setService('escaper', $escaper);

        $this->assertTrue(
            $micro->hasService('escaper')
        );

        unset(
            $micro['escaper']
        );

        $this->assertFalse(
            $micro->hasService('escaper')
        );
    }
}
