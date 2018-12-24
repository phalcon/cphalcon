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

namespace Phalcon\Test\Unit\Escaper;

use Phalcon\Escaper;
use UnitTester;

/**
 * Class EscapeCssCest
 */
class EscapeCssCest
{
    /**
     * Tests Phalcon\Escaper :: escapeCss()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-16
     */
    public function escaperEscapeCss(UnitTester $I)
    {
        $I->wantToTest("Escaper - escapeCss()");
        $escaper = new Escaper();
        $source  = ".émotion { background: "
            . "url('http://phalconphp.com/a.php?c=d&e=f'); }";

        $expected = '\2e \e9 motion\20 \7b \20 background\3a \20 url\28 '
            . '\27 http\3a \2f \2f phalconphp\2e com\2f a\2e php'
            . '\3f c\3d d\26 e\3d f\27 \29 \3b \20 \7d ';
        $actual   = $escaper->escapeCss($source);
        $I->assertEquals($expected, $actual);
    }
}
