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

final class GetSetUserOptionTest extends AbstractUnitTestCase
{
    use FormsTrait;

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementGetSetUserOption(
        string $class
    ): void {
        $name   = uniqid();
        $object = new $class($name);

        $expected = 'fallback';
        $actual   = $object->getUserOption('one', 'fallback');
        $this->assertSame($expected, $actual);

        $object->setUserOption('one', 'four');

        $expected = 'four';
        $actual   = $object->getUserOption('one', 'fallback');
        $this->assertSame($expected, $actual);
    }
}
