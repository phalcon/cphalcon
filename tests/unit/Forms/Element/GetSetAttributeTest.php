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

namespace Phalcon\Tests\Unit\Forms\Element;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FormsTrait;

use function uniqid;

final class GetSetAttributeTest extends AbstractUnitTestCase
{
    use FormsTrait;

    /**
     * @dataProvider getExamplesWithoutSelect
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementGetSetAttribute(
        string $class
    ): void {
        $name = uniqid();
        $data = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $object = new $class($name);

        $expected = 'fallback';
        $actual   = $object->getAttribute('one', 'fallback');
        $this->assertSame($expected, $actual);

        $object = new $class($name, $data);

        $expected = 'two';
        $actual   = $object->getAttribute('one', 'fallback');
        $this->assertSame($expected, $actual);

        $object->setAttribute('one', 'four');

        $expected = 'four';
        $actual   = $object->getAttribute('one', 'fallback');
        $this->assertSame($expected, $actual);
    }
}
