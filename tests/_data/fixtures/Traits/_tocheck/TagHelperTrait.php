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

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Html\Tag;
use UnitTester;

trait TagHelperTrait
{
    /**
     * Tests Phalcon\Tag :: input*()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagField(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Tag - %s() - parameters',
                $this->function
            )
        );

        $tag = new Tag();

        $tag->setDI(
            $this->container
        );

        $options = [
            'class' => 'x_class',
        ];

        $expected = '<input type="' . $this->inputType . '" id="x_name" name="x_name" class="x_class"';

        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected);
        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected, true);
    }

    /**
     * Runs the test for a Tag::$function with $options
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

    /**
     * Tests Phalcon\Tag :: input*() - parameters and id in it
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagFieldParameterWithId(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Tag - %s() - parameters with id',
                $this->function
            )
        );

        $tag = new Tag();

        $tag->setDI(
            $this->container
        );

        $options = [
            'name'  => 'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<input type="' . $this->inputType . '" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected);
        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected, true);
    }

    /**
     * Tests Phalcon\Tag :: input*() - setAttribute
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagFieldWithSetAttribute(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Tag - %s() - setAttribute()',
                $this->function
            )
        );

        $tag = new Tag();

        $tag->setDI(
            $this->container
        );

        $options = [
            'name'  => 'x_name',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<input type="' . $this->inputType . '" id="x_name" name="x_name" value="x_value" class="x_class" size="10"';

        if ($this->inputType === 'radio' || $this->inputType === 'checkbox') {
            $expected .= ' checked="checked"';
        }

        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected, false, 'setAttribute');
        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected, true, 'setAttribute');
    }

    /**
     * Tests Phalcon\Tag :: input*() - setAttribute and element not present
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagFieldWithSetAttributeElementNotPresent(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Tag - %s() - setAttribute() element not present',
                $this->function
            )
        );

        $tag = new Tag();

        $tag->setDI(
            $this->container
        );

        $options = [
            'name'  => 'x_name',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<input type="' . $this->inputType . '" id="x_name" name="x_name" value="x_value" class="x_class" size="10"';

        if ($this->inputType === 'radio' || $this->inputType === 'checkbox') {
            $expected .= ' checked="checked"';
        }

        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected, false, 'setAttribute');
        $this->testFieldParameter($I, $tag, 'x_name', $this->function, $options, $expected, true, 'setAttribute');
    }
}
