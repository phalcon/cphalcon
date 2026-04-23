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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\ToObject;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class ToObjectTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrArrayToObject(): void
    {
        $object = new ToObject();
        $source = [
            'one'   => 'two',
            'three' => 'four',
        ];


        $expected = new stdClass();
        $expected->one = 'two';
        $expected->three = 'four';

        $actual = $object($source);
        $this->assertEquals($expected, $actual);
    }
}
