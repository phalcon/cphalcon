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

namespace Phalcon\Tests\Unit\Annotations\Adapter;

use Codeception\Example;
use Phalcon\Annotations\Reader;
use Phalcon\Tests\Fixtures\Traits\AnnotationsTrait;
use UnitTester;

use function dataDir;

class GetSetReaderCest
{
    use AnnotationsTrait;

    /**
     * Tests Phalcon\Annotations\Adapter :: getReader()/setReader()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-12-30
     */
    public function annotationsAdapterGetSetReader(
        UnitTester $I,
        Example $example
    ) {
        $I->wantToTest('Annotations\Adapter getReader()/setReader()');

        require_once dataDir('fixtures/Annotations/TestClass.php');

        $class   = $example['class'];
        $params  = $example['params'];
        $adapter = new $class($params);

        $reader = new Reader();
        $adapter->setReader($reader);

        $expected = $reader;
        $actual   = $adapter->getReader();
        $I->assertSame($expected, $actual);

        $expected = Reader::class;
        $actual   = $adapter->getReader();
        $I->assertInstanceOf($expected, $actual);
    }
}
