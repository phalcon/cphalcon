<?php

namespace Phalcon\Test\Unit\Translate\Adapter;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Translate\Adapter\NativeArray;

/**
 * \Phalcon\Test\Unit\Translate\Adapter\NativeArrayTest
 * Tests the \Phalcon\Translate\Adapter\NativeArray component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Translate\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class NativeArrayTest extends UnitTest
{
    private $config = null;

    /**
     * Initialize data for the tests
     */
    public function _before()
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
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testExists()
    {
        $this->specify(
            "The key does not exist with exists",
            function () {
                $language   = $this->config['en'];
                $translator = new NativeArray(['content' => $language]);
                expect($translator->exists('hi'))->true();
            }
        );
    }

    /**
     * Tests whether a key exists in the array with offsetExists
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testOffsetExists()
    {
        $this->specify(
            "The key does not exist with offsetExists",
            function () {
                $language   = $this->config['en'];
                $translator = new NativeArray(['content' => $language]);
                expect($translator->offsetExists('hi'))->true();
            }
        );
    }

    /**
     * Tests the offsetGet
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testOffsetGet()
    {
        $this->specify(
            "The key does not exist with offsetGet",
            function () {
                $language   = $this->config['en'];
                $translator = new NativeArray(['content' => $language]);
                expect($translator->offsetGet('hi'))->equals('Hello');
            }
        );
    }

    /**
     * Tests the query with English
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testQueryEnglish()
    {
        $this->specify(
            "The key does not exist with query in English",
            function () {
                $language   = $this->config['en'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->query('hi'))->equals('Hello');
                expect($translator->query('bye'))->equals('Good Bye');
            }
        );

        $this->specify(
            "The key does not exist with query in English with alternative syntax",
            function () {
                $language   = $this->config['en'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->_('hi'))->equals('Hello');
                expect($translator->_('bye'))->equals('Good Bye');
            }
        );
    }

    /**
     * Tests the query with Spanish
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testQuerySpanish()
    {
        $this->specify(
            "The key does not exist with query in Spanish",
            function () {
                $language   = $this->config['es'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->query('hi'))->equals('Hola');
                expect($translator->query('bye'))->equals('Adiós');
            }
        );

        $this->specify(
            "The key does not exist with query in Spanish with alternative syntax",
            function () {
                $language   = $this->config['es'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->_('hi'))->equals('Hola');
                expect($translator->_('bye'))->equals('Adiós');
            }
        );
    }

    /**
     * Tests the query with French
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testQueryFrench()
    {
        $this->specify(
            "The key does not exist with query in French",
            function () {
                $language   = $this->config['fr'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->query('hi'))->equals('Bonjour');
                expect($translator->query('bye'))->equals('Au revoir');
            }
        );

        $this->specify(
            "The key does not exist with query in French with alternative syntax",
            function () {
                $language   = $this->config['fr'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->_('hi'))->equals('Bonjour');
                expect($translator->_('bye'))->equals('Au revoir');
            }
        );
    }

    /**
     * Tests variable substitution in string with no variables - English
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionInStringWithNoVariablesEnglish()
    {
        $this->specify(
            "Translator does not translate English correctly with passed params and no variables",
            function () {
                $language   = $this->config['en'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->_('hi', ['name' => 'my friend']))->equals('Hello');
            }
        );
    }

    /**
     * Tests variable substitution in string (one variable) - English
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionOneEnglish()
    {
        $this->specify(
            "Translator does not translate English correctly with parameters",
            function () {
                $language   = $this->config['en'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->_('hello-key', ['name' => 'my friend']))->equals('Hello my friend');
            }
        );
    }

    /**
     * Tests variable substitution in string (two variable) - English
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionTwoEnglish()
    {
        $this->specify(
            "Translator does not translate English correctly - many parameters",
            function () {
                $language   = $this->config['en'];
                $translator = new NativeArray(['content' => $language]);

                $vars = [
                    'song'   => 'Dust in the wind',
                    'artist' => 'Kansas',
                ];

                expect($translator->_('song-key', $vars))->equals('This song is Dust in the wind (Kansas)');
            }
        );
    }

    /**
     * Tests variable substitution in string with no variables - Spanish
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionInStringWithNoVariablesSpanish()
    {
        $this->specify(
            "Translator does not translate Spanish correctly with passed params and no variables",
            function () {
                $language   = $this->config['es'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->_('hi', ['name' => 'my friend']))->equals('Hola');
            }
        );
    }

    /**
     * Tests variable substitution in string (one variable) - Spanish
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionOneSpanish()
    {
        $this->specify(
            "Translator does not translate Spanish correctly with parameters",
            function () {
                $language   = $this->config['es'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->_('hello-key', ['name' => 'my friend']))->equals('Hola my friend');
            }
        );
    }

    /**
     * Tests variable substitution in string (two variable) - Spanish
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionTwoSpanish()
    {
        $this->specify(
            "Translator does not translate Spanish correctly - many parameters",
            function () {
                $language   = $this->config['es'];
                $translator = new NativeArray(['content' => $language]);

                $vars = [
                    'song'   => 'Dust in the wind',
                    'artist' => 'Kansas',
                ];

                expect($translator->_('song-key', $vars))->equals('La canción es Dust in the wind (Kansas)');
            }
        );
    }

    /**
     * Tests variable substitution in string with no variables - French
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionInStringWithNoVariablesFrench()
    {
        $this->specify(
            "Translator does not translate French correctly with passed params and no variables",
            function () {
                $language   = $this->config['fr'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->_('hi', ['name' => 'my friend']))->equals('Bonjour');
            }
        );
    }

    /**
     * Tests variable substitution in string (one variable) - French
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionOneFrench()
    {
        $this->specify(
            "Translator does not translate French correctly with parameters",
            function () {
                $language   = $this->config['fr'];
                $translator = new NativeArray(['content' => $language]);

                expect($translator->_('hello-key', ['name' => 'my friend']))->equals('Bonjour my friend');
            }
        );
    }

    /**
     * Tests variable substitution in string (two variable) - French
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testVariableSubstitutionTwoFrench()
    {
        $this->specify(
            "Translator does not translate French correctly - many parameters",
            function () {
                $language   = $this->config['fr'];
                $translator = new NativeArray(['content' => $language]);

                $vars = [
                    'song'   => 'Dust in the wind',
                    'artist' => 'Kansas',
                ];

                expect($translator->_('song-key', $vars))->equals('La chanson est Dust in the wind (Kansas)');
            }
        );
    }

    /**
     * Tests translator with array access
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testWithArrayAccess()
    {
        $this->specify(
            "Translator with array access",
            function () {
                $language   = $this->config['ru'];
                $translator = new NativeArray(['content' => $language]);

                expect(isset($translator['Hello!']))->true();
                expect(isset($translator['Hi there!']))->false();
                expect($translator['Hello!'])->equals($language['Hello!']);
            }
        );
    }

    /**
     * Tests translator with array access and UTF8 strings
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testWithArrayAccessAndUTF8Strings()
    {
        $this->specify(
            "Translator with array access and UTF8 strings",
            function () {
                $language   = $this->config['ru'];
                $translator = new NativeArray(['content' => $language]);

                $vars = [
                    'fname' => 'John',
                    'lname' => 'Doe',
                    'mname' => 'D.',
                ];

                expect($translator->_('Hello %fname% %mname% %lname%!', $vars))->equals('Привет, John D. Doe!');
            }
        );
    }
}
