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

use Phalcon\Forms\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FormsTrait;

use function array_flip;
use function uniqid;

final class GetSetFiltersTest extends AbstractUnitTestCase
{
    use FormsTrait;

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementGetSetAddFilters(
        string $class
    ): void {
        $name    = uniqid();
        $data    = [
            'trim',
            'striptags',
        ];
        $flipped = array_flip($data);
        $object  = new $class($name);

        $expected = [];
        $actual   = $object->getFilters();
        $this->assertSame($expected, $actual);

        $object->setFilters($flipped);

        $expected = $flipped;
        $actual   = $object->getFilters();
        $this->assertSame($expected, $actual);

        $object->setFilters('lower');

        $expected = ['lower'];
        $actual   = $object->getFilters();
        $this->assertSame($expected, $actual);

        $object->addFilter('trim');

        $expected = ['lower', 'trim'];
        $actual   = $object->getFilters();
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementSetFiltersException(
        string $class
    ): void {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The filter needs to be an array or string');

        $object = new $class(uniqid());
        $object->setFilters(1234);
    }
}
