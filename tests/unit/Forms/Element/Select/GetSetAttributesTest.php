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

namespace Phalcon\Tests\Unit\Forms\Element\Select;

use Phalcon\Forms\Element\Select;
use Phalcon\Tests\AbstractUnitTestCase;

use function array_flip;
use function uniqid;

final class GetSetAttributesTest extends AbstractUnitTestCase
{
    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementSelectGetSetAttributes(): void
    {
        $name    = uniqid();
        $data    = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $flipped = array_flip($data);

        $object = new Select($name);

        $actual = $object->getAttributes();
        $this->assertEmpty($actual);

        $object = new Select($name, null, $data);

        $expected = $data;
        $actual   = $object->getAttributes();
        $this->assertSame($expected, $actual);

        $object->setAttributes($flipped);

        $expected = $flipped;
        $actual   = $object->getAttributes();
        $this->assertSame($expected, $actual);
    }
}
