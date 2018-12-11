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

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Html\Tag;
use UnitTester;

/**
 * Trait TagSetupTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait TagHelperTrait
{
    /**
     * Tests Phalcon\Tag :: input*()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagField(UnitTester $I)
    {
        $I->wantToTest(sprintf('Tag - %s() - parameters', $this->function));
        $tag = new Tag();
        $tag->setDI($this->container);

        $options  = [
            'class' => 'x_class',
        ];
        $expected = '<input type="' . $this->inputType . '" id="x_name" name="x_name" class="x_class"';

        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected);
        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected, true);
    }
//
//    /**
//     * Tests Phalcon\Tag :: input*() - parameters and id in it
//     *
//     * @author Phalcon Team <team@phalconphp.com>
//     * @since  2014-09-05
//     */
//    public function tagFieldParameterWithId(UnitTester $I)
//    {
//        $I->wantToTest(sprintf('Tag - %s() - parameters with id', $this->function));
//        $tag = new Tag();
//        $tag->setDI($this->container);
//
//        $options  = [
//            'name'  => 'x_name',
//            'id'    => 'x_id',
//            'class' => 'x_class',
//            'size'  => '10',
//        ];
//        $expected = '<input type="' . $this->inputType . '" id="x_id" name="x_name" '
//            . 'class="x_class" size="10"';
//
//        $this->testFieldParameter($I, $tag, $this->function, $options, $expected);
//        $this->testFieldParameter($I, $tag, $this->function, $options, $expected, true);
//    }
//
//    /**
//     * Tests Phalcon\Tag :: input*() - setDefault
//     *
//     * @author Phalcon Team <team@phalconphp.com>
//     * @since  2014-09-05
//     */
//    public function tagFieldWithSetDefault(UnitTester $I)
//    {
//        $I->wantToTest(sprintf('Tag - %s() - setDefault()', $this->function));
//        $tag = new Tag();
//        $tag->setDI($this->container);
//
//        $options  = [
//            'name'  => 'x_name',
//            'class' => 'x_class',
//            'size'  => '10',
//        ];
//        $expected = '<input type="' . $this->inputType . '" id="x_name" '
//            . 'name="x_name" value="x_value" class="x_class" size="10"';
//
//        $this->testFieldParameter($I, $tag, $this->function, $options, $expected, false, 'setDefault');
//        $this->testFieldParameter($I, $tag, $this->function, $options, $expected, true, 'setDefault');
//    }
//
//    /**
//     * Tests Phalcon\Tag :: input*() - setDefault and element not present
//     *
//     * @author Phalcon Team <team@phalconphp.com>
//     * @since  2014-09-05
//     */
//    public function tagFieldWithSetDefaultElementNotPresent(UnitTester $I)
//    {
//        $I->wantToTest(sprintf('Tag - %s() - setDefault() element not present', $this->function));
//        $tag = new Tag();
//        $tag->setDI($this->container);
//
//        $options  = [
//            'name'  => 'x_name',
//            'class' => 'x_class',
//            'size'  => '10',
//        ];
//        $expected = '<input type="' . $this->inputType . '" id="x_name" '
//            . 'name="x_name" value="x_value" class="x_class" '
//            . 'size="10"';
//
//        $this->testFieldParameter($I, $tag, $this->function, $options, $expected, false, 'setDefault');
//        $this->testFieldParameter($I, $tag, $this->function, $options, $expected, true, 'setDefault');
//    }

    /**
     * Runs the test for a Tag::$function with $options
     *
     * @param \UnitTester $I
     * @param string      $name
     * @param string      $function
     * @param mixed       $options
     * @param string      $expected
     * @param boolean     $xhtml
     * @param string      $set
     */
    abstract protected function testFieldParameter(
        UnitTester $I,
        Tag $tag,
        string $name,
        string $function,
        $options,
        string $expected,
        bool $xhtml = false,
        string $set = ''
    );
}
