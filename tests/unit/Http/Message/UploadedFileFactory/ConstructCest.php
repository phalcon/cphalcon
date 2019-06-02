<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\ServerUploadedFileFactory;

use Phalcon\Http\Message\UploadedFileFactory;
use Psr\Http\Message\UploadedFileFactoryInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\ServerUploadedFileFactory :: __construct()
     *
     * @since  2019-02-08
     */
    public function httpUploadedFileFactoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\UploadedFileFactory - __construct()');

        $factory = new UploadedFileFactory();
        $class   = UploadedFileFactoryInterface::class;
        $I->assertInstanceOf($class, $factory);
    }
}
