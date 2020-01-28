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

namespace Phalcon\Test\Unit\Html\Helper;

use Phalcon\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Close;
use Phalcon\Html\TagFactory;
use UnitTester;

class CloseCest
{
    /**
     * Tests Phalcon\Html\Helper\Close :: __construct()
     *
     * @throws Exception
     */
    public function htmlHelperCloseConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\FormClose - __construct()');
        $escaper = new Escaper();
        $helper  = new Close($escaper);

        $expected = '</form>';
        $actual   = $helper('form');
        $I->assertEquals($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('close');
        $actual  = $locator('form');
        $I->assertEquals($expected, $actual);
    }
}
