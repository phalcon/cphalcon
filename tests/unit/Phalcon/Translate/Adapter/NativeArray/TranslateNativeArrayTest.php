<?php
/**
 * TranslateNativeArrayTest.php
 * \Phalcon\Translate\Adapter\NativeArray
 *
 * Tests the \Phalcon\Translate\Adapter\NativeArray component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Translate\Adapter\NativeArray;

use Phalcon\Translate\Adapter\NativeArray as PhTTranslateAdapterNativeArray;
use \Codeception\TestCase\Test as CdTest;
use \Codeception\Specify as CdSpecify;

class TranslateNativeArrayTest extends CdTest
{
    use CdSpecify;

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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);
                $found      = $translator->exists('hi');

                expect($found)->true();
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);
                $found      = $translator->offsetExists('hi');

                expect($found)->true();
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);
                $expected   = 'Hello';
                $actual     = $translator->offsetGet('hi');

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $expected   = 'Hello';
                $actual     = $translator->query('hi');

                expect($actual)->equals($expected);

                $expected   = 'Good Bye';
                $actual     = $translator->query('bye');

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The key does not exist with query in English with alternative syntax",
            function () {

                $language   = $this->config['en'];
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $expected   = 'Hello';
                $actual     = $translator->_('hi');

                expect($actual)->equals($expected);

                $expected   = 'Good Bye';
                $actual     = $translator->_('bye');

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $expected   = 'Hola';
                $actual     = $translator->query('hi');

                expect($actual)->equals($expected);

                $expected   = 'Adiós';
                $actual     = $translator->query('bye');

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The key does not exist with query in Spanish with alternative syntax",
            function () {

                $language   = $this->config['es'];
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $expected   = 'Hola';
                $actual     = $translator->_('hi');

                expect($actual)->equals($expected);

                $expected   = 'Adiós';
                $actual     = $translator->_('bye');

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $expected   = 'Bonjour';
                $actual     = $translator->query('hi');

                expect($actual)->equals($expected);

                $expected   = 'Au revoir';
                $actual     = $translator->query('bye');

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The key does not exist with query in French with alternative syntax",
            function () {

                $language   = $this->config['fr'];
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $expected   = 'Bonjour';
                $actual     = $translator->_('hi');

                expect($actual)->equals($expected);

                $expected   = 'Au revoir';
                $actual     = $translator->_('bye');

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $vars     = ['name' => 'my friend'];
                $expected = 'Hello';
                $actual   = $translator->_('hi', $vars);

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $vars     = ['name' => 'my friend'];
                $expected = 'Hello my friend';
                $actual   = $translator->_('hello-key', $vars);

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $vars     = [
                    'song'   => 'Dust in the wind',
                    'artist' => 'Kansas',
                ];
                $expected = 'This song is Dust in the wind (Kansas)';
                $actual   = $translator->_('song-key', $vars);

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $vars     = ['name' => 'my friend'];
                $expected = 'Hola';
                $actual   = $translator->_('hi', $vars);

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $vars     = ['name' => 'my friend'];
                $expected = 'Hola my friend';
                $actual   = $translator->_('hello-key', $vars);

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $vars     = [
                    'song'   => 'Dust in the wind',
                    'artist' => 'Kansas',
                ];
                $expected = 'La canción es Dust in the wind (Kansas)';
                $actual   = $translator->_('song-key', $vars);

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $vars     = ['name' => 'my friend'];
                $expected = 'Bonjour';
                $actual   = $translator->_('hi', $vars);

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $vars     = ['name' => 'my friend'];
                $expected = 'Bonjour my friend';
                $actual   = $translator->_('hello-key', $vars);

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $vars     = [
                    'song'   => 'Dust in the wind',
                    'artist' => 'Kansas',
                ];
                $expected = 'La chanson est Dust in the wind (Kansas)';
                $actual   = $translator->_('song-key', $vars);

                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $expected = $language['Hello!'];
                $actual   = $translator['Hello!'];

                expect(isset($translator['Hello!']))->true();
                expect(isset($translator['Hi there!']))->false();
                expect($actual)->equals($expected);
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
                $params     = ['content' => $language];
                $translator = new PhTTranslateAdapterNativeArray($params);

                $expected = 'Привет, John D. Doe!';
                $actual = $translator->_(
                    'Hello %fname% %mname% %lname%!',
                    [
                        'fname' => 'John',
                        'lname' => 'Doe',
                        'mname' => 'D.',
                    ]
                );
                expect($actual)->equals($expected);
            }
        );
    }
}
