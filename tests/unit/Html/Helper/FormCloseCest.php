<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Helper;

use Phalcon\Html\Helper\FormClose;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class FormCloseCest
 */
class FormCloseCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Html\Helper\FormClose :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-01-19
     */
    public function htmlHelperFormcloseConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\FormClose - __construct()');
        $escaper = $this->newEscaper();
        $helper  = new FormClose($escaper);

        $expected = '</form>';
        $actual   = $helper();
        $I->assertEquals($expected, $actual);
    }
}
