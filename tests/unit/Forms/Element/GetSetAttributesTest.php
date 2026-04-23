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

use Phalcon\Forms\Element\Check;
use Phalcon\Forms\Element\Date;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\File;
use Phalcon\Forms\Element\Hidden;
use Phalcon\Forms\Element\Numeric;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Submit;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;
use Phalcon\Tests\AbstractUnitTestCase;

use function array_flip;
use function uniqid;

final class GetSetAttributesTest extends AbstractUnitTestCase
{
    /**
     * @return string[][]
     */
    public static function getExamples(): array
    {
        return [
            [Check::class],
            [Date::class],
            [Email::class],
            [File::class],
            [Hidden::class],
            [Numeric::class],
            [Password::class],
            [Radio::class],
            [Submit::class],
            [Text::class],
            [TextArea::class],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementGetSetAttributes(
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
        $actual   = $object->getAttributes();
        $this->assertSame($expected, $actual);

        $object = new $class($name, $data);

        $expected = $data;
        $actual   = $object->getAttributes();
        $this->assertSame($expected, $actual);

        $object->setAttributes($flipped);

        $expected = $flipped;
        $actual   = $object->getAttributes();
        $this->assertSame($expected, $actual);
    }
}
