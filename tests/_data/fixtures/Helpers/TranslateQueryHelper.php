<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Helpers;

use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use UnitTester;

class TranslateQueryHelper
{
    use TranslateTrait;
    
    protected $function = '_';

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() - English
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queryEnglish(UnitTester $I)
    {
        $I->wantToTest(
            sprintf('Translate\Adapter\NativeArray - %s() - english', $this->function)
        );
        $language   = $this->getArrayConfig()['en'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hello';
        $actual   = $translator->{$this->function}('hi');
        $I->assertEquals($expected, $actual);

        $expected = 'Good Bye';
        $actual   = $translator->{$this->function}('bye');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() - Spanish
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function querySpanish(UnitTester $I)
    {
        $I->wantToTest(
            sprintf('Translate\Adapter\NativeArray - %s() - spanish', $this->function)
        );
        $language   = $this->getArrayConfig()['es'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hola';
        $actual   = $translator->{$this->function}('hi');
        $I->assertEquals($expected, $actual);

        $expected = 'Adiós';
        $actual   = $translator->{$this->function}('bye');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() - French
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function queryFrench(UnitTester $I)
    {
        $I->wantToTest(
            sprintf('Translate\Adapter\NativeArray - %s() - french', $this->function)
        );
        $language   = $this->getArrayConfig()['fr'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Bonjour';
        $actual   = $translator->{$this->function}('hi');
        $I->assertEquals($expected, $actual);

        $expected = 'Au revoir';
        $actual   = $translator->{$this->function}('bye');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string with no variables - English
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function variableSubstitutionInStringWithNoVariablesEnglish(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - variable substitution ' .
                'in string with no variables english',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['en'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hello';
        $actual   = $translator->{$this->function}('hi', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string (one variable) - English
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function variableSubstitutionOneEnglish(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - variable substitution one english',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['en'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hello my friend';
        $actual   = $translator->{$this->function}('hello-key', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string (two variable) - English
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function variableSubstitutionTwoEnglish(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - variable substitution two english',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['en'];
        $translator = new NativeArray(['content' => $language]);

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        $expected = 'This song is Dust in the wind (Kansas)';
        $actual   = $translator->{$this->function}('song-key', $vars);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string with no variables - Spanish
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function variableSubstitutionInStringWithNoVariablesSpanish(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - variable substitution ' .
                'in string with no variables spanish',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['es'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hola';
        $actual   = $translator->{$this->function}('hi', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string (one variable) - Spanish
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function variableSubstitutionOneSpanish(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - variable substitution one spanish',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['es'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hola my friend';
        $actual   = $translator->{$this->function}('hello-key', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string (two variable) - Spanish
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function variableSubstitutionTwoSpanish(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - variable substitution two spanish',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['es'];
        $translator = new NativeArray(['content' => $language]);

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        $expected = 'La canción es Dust in the wind (Kansas)';
        $actual   = $translator->{$this->function}('song-key', $vars);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string with no variables - French
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function variableSubstitutionInStringWithNoVariablesFrench(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - variable substitution ' .
                'in string with no variables french',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['fr'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Bonjour';
        $actual   = $translator->{$this->function}('hi', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string (one variable) - French
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function variableSubstitutionOneFrench(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - variable substitution one french',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['fr'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Bonjour my friend';
        $actual   = $translator->{$this->function}('hello-key', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string (two variable) - French
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function variableSubstitutionTwoFrench(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - variable substitution two french',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['fr'];
        $translator = new NativeArray(['content' => $language]);

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        $expected = 'La chanson est Dust in the wind (Kansas)';
        $actual   = $translator->{$this->function}('song-key', $vars);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() - array access and UTF8 strings
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function withArrayAccessAndUTF8Strings(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s() - with array access and UTF8 strings',
                $this->function
            )
        );
        $language   = $this->getArrayConfig()['ru'];
        $translator = new NativeArray(['content' => $language]);

        $vars = [
            'fname' => 'John',
            'lname' => 'Doe',
            'mname' => 'D.',
        ];

        $expected = 'Привет, John D. Doe!';
        $actual   = $translator->{$this->function}('Hello %fname% %mname% %lname%!', $vars);
        $I->assertEquals($expected, $actual);
    }
}
