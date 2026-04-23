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

use function array_flip;
use function uniqid;

final class GetSetUserOptionsTest extends AbstractUnitTestCase
{
    use FormsTrait;

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementGetSetUserOptions(
        string $class
    ): void {
        $name    = uniqid();
        $data    = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $flipped = array_flip($data);

        $object = new $class($name);

        $expected = [];
        $actual   = $object->getUserOptions();
        $this->assertSame($expected, $actual);

        $object->setUserOptions($flipped);

        $expected = $flipped;
        $actual   = $object->getUserOptions();
        $this->assertSame($expected, $actual);
    }
}
