<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter;

use Phalcon\Translate\Adapter\NativeArray;
use UnitTester;

class NativeArrayCest
{
    private $config = null;

    /**
     * Initialize data for the tests
     */
    public function _before(UnitTester $I)
    {
        $this->config = [
            'en' => [
                'hi'        => 'Hello',
                'bye'       => 'Good Bye',
                'hello-key' => 'Hello %name%',
                'song-key'  => 'This song is %song% (%artist%)',
            ],
            'es' => [
                'hi'        => 'Hola',
                'bye'       => 'Adiós',
                'hello-key' => 'Hola %name%',
                'song-key'  => 'La canción es %song% (%artist%)',
            ],
            'fr' => [
                'hi'        => 'Bonjour',
                'bye'       => 'Au revoir',
                'hello-key' => 'Bonjour %name%',
                'song-key'  => 'La chanson est %song% (%artist%)',
            ],
            'ru' => [
                'Hello!'                         => 'Привет!',
                'Hello %fname% %mname% %lname%!' => 'Привет, %fname% %mname% %lname%!',
            ],
        ];
    }

    /**
     * Tests whether a key exists in the array
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testExists(UnitTester $I)
    {
        $language   = $this->config['en'];
        $translator = new NativeArray(['content' => $language]);

        $actual = $translator->exists('hi');
        $I->assertTrue($actual);
    }

    /**
     * Tests whether a key exists in the array with offsetExists
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testOffsetExists(UnitTester $I)
    {
        $language   = $this->config['en'];
        $translator = new NativeArray(['content' => $language]);

        $actual = $translator->offsetExists('hi');
        $I->assertTrue($actual);
    }

    /**
     * Tests the offsetGet
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testOffsetGet(UnitTester $I)
    {
        $language   = $this->config['en'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hello';
        $actual   = $translator->offsetGet('hi');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the query with English
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testQueryEnglish(UnitTester $I)
    {
        $language   = $this->config['en'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hello';
        $actual   = $translator->query('hi');
        $I->assertEquals($expected, $actual);

        $expected = 'Good Bye';
        $actual   = $translator->query('bye');
        $I->assertEquals($expected, $actual);

        $expected = 'Hello';
        $actual   = $translator->_('hi');
        $I->assertEquals($expected, $actual);

        $expected = 'Good Bye';
        $actual   = $translator->_('bye');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the query with Spanish
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testQuerySpanish(UnitTester $I)
    {
        $language   = $this->config['es'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hola';
        $actual   = $translator->query('hi');
        $I->assertEquals($expected, $actual);

        $expected = 'Adiós';
        $actual   = $translator->query('bye');
        $I->assertEquals($expected, $actual);

        $expected = 'Hola';
        $actual   = $translator->_('hi');
        $I->assertEquals($expected, $actual);

        $expected = 'Adiós';
        $actual   = $translator->_('bye');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the query with French
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testQueryFrench(UnitTester $I)
    {
        $language   = $this->config['fr'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Bonjour';
        $actual   = $translator->query('hi');
        $I->assertEquals($expected, $actual);

        $expected = 'Au revoir';
        $actual   = $translator->query('bye');
        $I->assertEquals($expected, $actual);

        $expected = 'Bonjour';
        $actual   = $translator->_('hi');
        $I->assertEquals($expected, $actual);

        $expected = 'Au revoir';
        $actual   = $translator->_('bye');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests variable substitution in string with no variables - English
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionInStringWithNoVariablesEnglish(UnitTester $I)
    {
        $language   = $this->config['en'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hello';
        $actual   = $translator->query('hi', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);

        $expected = 'Hello';
        $actual   = $translator->_('hi', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests variable substitution in string (one variable) - English
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionOneEnglish(UnitTester $I)
    {
        $language   = $this->config['en'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hello my friend';
        $actual   = $translator->query('hello-key', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);

        $expected = 'Hello my friend';
        $actual   = $translator->_('hello-key', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests variable substitution in string (two variable) - English
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionTwoEnglish(UnitTester $I)
    {
        $language   = $this->config['en'];
        $translator = new NativeArray(['content' => $language]);

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        $expected = 'This song is Dust in the wind (Kansas)';
        $actual   = $translator->query('song-key', $vars);
        $I->assertEquals($expected, $actual);

        $expected = 'This song is Dust in the wind (Kansas)';
        $actual   = $translator->_('song-key', $vars);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests variable substitution in string with no variables - Spanish
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionInStringWithNoVariablesSpanish(UnitTester $I)
    {
        $language   = $this->config['es'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hola';
        $actual   = $translator->query('hi', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);

        $expected = 'Hola';
        $actual   = $translator->_('hi', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests variable substitution in string (one variable) - Spanish
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionOneSpanish(UnitTester $I)
    {
        $language   = $this->config['es'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Hola my friend';
        $actual   = $translator->query('hello-key', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);

        $expected = 'Hola my friend';
        $actual   = $translator->_('hello-key', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests variable substitution in string (two variable) - Spanish
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionTwoSpanish(UnitTester $I)
    {
        $language   = $this->config['es'];
        $translator = new NativeArray(['content' => $language]);

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        $expected = 'La canción es Dust in the wind (Kansas)';
        $actual   = $translator->query('song-key', $vars);
        $I->assertEquals($expected, $actual);

        $expected = 'La canción es Dust in the wind (Kansas)';
        $actual   = $translator->_('song-key', $vars);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests variable substitution in string with no variables - French
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionInStringWithNoVariablesFrench(UnitTester $I)
    {
        $language   = $this->config['fr'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Bonjour';
        $actual   = $translator->query('hi', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);

        $expected = 'Bonjour';
        $actual   = $translator->_('hi', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests variable substitution in string (one variable) - French
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionOneFrench(UnitTester $I)
    {
        $language   = $this->config['fr'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'Bonjour my friend';
        $actual   = $translator->query('hello-key', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);

        $expected = 'Bonjour my friend';
        $actual   = $translator->_('hello-key', ['name' => 'my friend']);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests variable substitution in string (two variable) - French
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionTwoFrench(UnitTester $I)
    {
        $language   = $this->config['fr'];
        $translator = new NativeArray(['content' => $language]);

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        $expected = 'La chanson est Dust in the wind (Kansas)';
        $actual   = $translator->query('song-key', $vars);
        $I->assertEquals($expected, $actual);

        $expected = 'La chanson est Dust in the wind (Kansas)';
        $actual   = $translator->_('song-key', $vars);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests translator with array access
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testWithArrayAccess(UnitTester $I)
    {
        $language   = $this->config['ru'];
        $translator = new NativeArray(['content' => $language]);

        $actual = isset($translator['Hello!']);
        $I->assertTrue($actual);

        $actual = isset($translator['Hi there!']);
        $I->assertFalse($actual);

        $expected = $language['Hello!'];
        $actual   = $translator['Hello!'];
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests translator with array access and UTF8 strings
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testWithArrayAccessAndUTF8Strings(UnitTester $I)
    {
        $language   = $this->config['ru'];
        $translator = new NativeArray(['content' => $language]);

        $vars = [
            'fname' => 'John',
            'lname' => 'Doe',
            'mname' => 'D.',
        ];

        $expected = 'Привет, John D. Doe!';
        $actual   = $translator->query('Hello %fname% %mname% %lname%!', $vars);
        $I->assertEquals($expected, $actual);

        $expected = 'Привет, John D. Doe!';
        $actual   = $translator->_('Hello %fname% %mname% %lname%!', $vars);
        $I->assertEquals($expected, $actual);
    }
}
