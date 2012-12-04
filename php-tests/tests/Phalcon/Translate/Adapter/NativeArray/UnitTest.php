<?php
/**
 * UnitTest.php
 * \Phalcon\Translate\Adapter\NativeArray\UnitTest
 *
 * Tests the \Phalcon\Translate\Adapter\NativeArray component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2013 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Translate\Exception as TrEx;
use \Phalcon\Translate\Adapter\NativeArray as TrNA;

class Translate_Adapter_NativeArray_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Tests Exists
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testExists()
    {
        $language   = $this->_config['tr']['en'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $found = $translator->exists('hi');

        $this->assertTrue(
            $found,
            'Translator key does not exist'
        );
    }

    /**
     * Tests offsetExists
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testOffsetExists()
    {
        $language   = $this->_config['tr']['en'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $found = $translator->offsetExists('hi');

        $this->assertTrue(
            $found,
            'Translator key does not exist'
        );
    }

    /**
     * Tests offsetGet
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testOffsetGet()
    {
        $language   = $this->_config['tr']['en'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $expected = 'Hello';
        $actual   = $translator->offsetGet('hi');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not return proper string with offsetGet'
        );
    }

    /**
     * Tests English
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testQueryEnglish()
    {
        $language   = $this->_config['tr']['en'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $expected = 'Hello';
        $actual   = $translator->query('hi');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate English correctly'
        );

        $expected = 'Good Bye';
        $actual   = $translator->query('bye');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate English correctly'
        );
    }

    /**
     * Tests Spanish
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testQuerySpanish()
    {
        $language   = $this->_config['tr']['es'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $expected = 'Hola';
        $actual   = $translator->query('hi');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate Spanish correctly'
        );

        $expected = 'Adiós';
        $actual   = $translator->query('bye');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate Spanish correctly'
        );
    }

    /**
     * Tests French
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testQueryFrench()
    {
        $language   = $this->_config['tr']['fr'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $expected = 'Bonjour';
        $actual   = $translator->query('hi');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate French correctly'
        );

        $expected = 'Au revoir';
        $actual   = $translator->query('bye');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate French correctly'
        );
    }

    /**
     * Tests English - alternative syntax
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testQueryEnglishAlternative()
    {
        $language   = $this->_config['tr']['en'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $expected = 'Hello';
        $actual   = $translator->_('hi');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate English correctly'
        );

        $expected = 'Good Bye';
        $actual   = $translator->_('bye');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate English correctly'
        );
    }

    /**
     * Tests Spanish - alternative syntax
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testQuerySpanishAlternative()
    {
        $language   = $this->_config['tr']['es'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $expected = 'Hola';
        $actual   = $translator->_('hi');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate Spanish correctly'
        );

        $expected = 'Adiós';
        $actual   = $translator->_('bye');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate Spanish correctly'
        );
    }

    /**
     * Tests French - alternative syntax
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testQueryFrenchAlternative()
    {
        $language   = $this->_config['tr']['fr'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $expected = 'Bonjour';
        $actual   = $translator->_('hi');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate French correctly'
        );

        $expected = 'Au revoir';
        $actual   = $translator->_('bye');

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate French correctly'
        );
    }

    /**
     * Tests variable substitution in string with no variables - English
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testVariableSubstitutionInStringWithNoVariablesEnglish()
    {
        $language   = $this->_config['tr']['en'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $vars     = array('name' => 'my friend');
        $expected = 'Hello';
        $actual   = $translator->_('hi', $vars);

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate English correctly with passed params'
        );
    }

    /**
     * Tests variable substitution in string (one variable) - English
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testVariableSubstitutionOneEnglish()
    {
        $language   = $this->_config['tr']['en'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $vars     = array('name' => 'my friend');
        $expected = 'Hello my friend';
        $actual   = $translator->_('hello-key', $vars);

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate English correctly with parameters'
        );
    }

    /**
     * Tests variable substitution in string (two variable) - English
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testVariableSubstitutionTwoEnglish()
    {
        $language   = $this->_config['tr']['en'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $vars     = array(
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        );
        $expected = 'This song is Dust in the wind (Kansas)';
        $actual   = $translator->_('song-key', $vars);

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate English correctly - many parameters'
        );
    }

    /**
     * Tests variable substitution in string with no variables - Spanish
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testVariableSubstitutionInStringWithNoVariablesSpanish()
    {
        $language   = $this->_config['tr']['es'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $vars     = array('name' => 'amigo');
        $expected = 'Hola';
        $actual   = $translator->_('hi', $vars);

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate Spanish correctly with passed params'
        );
    }

    /**
     * Tests variable substitution in string (one variable) - Spanish
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testVariableSubstitutionOneSpanish()
    {
        $language   = $this->_config['tr']['es'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $vars     = array('name' => 'amigo');
        $expected = 'Hola amigo';
        $actual   = $translator->_('hello-key', $vars);

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate Spanish correctly with parameters'
        );
    }

    /**
     * Tests variable substitution in string (two variable) - Spanish
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testVariableSubstitutionTwoSpanish()
    {
        $language   = $this->_config['tr']['es'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $vars     = array(
                        'song'   => 'Dust in the wind',
                        'artist' => 'Kansas',
                    );
        $expected = 'La canción es Dust in the wind (Kansas)';
        $actual   = $translator->_('song-key', $vars);

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate French correctly - many parameters'
        );
    }

    /**
     * Tests variable substitution in string with no variables - French
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testVariableSubstitutionInStringWithNoVariablesFrench()
    {
        $language   = $this->_config['tr']['fr'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $vars     = array('name' => 'mon ami');
        $expected = 'Bonjour';
        $actual   = $translator->_('hi', $vars);

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate French correctly with passed params'
        );
    }

    /**
     * Tests variable substitution in string (one variable) - French
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testVariableSubstitutionOneFrench()
    {
        $language   = $this->_config['tr']['fr'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $vars     = array('name' => 'mon ami');
        $expected = 'Bonjour mon ami';
        $actual   = $translator->_('hello-key', $vars);

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate French correctly with parameters'
        );
    }

    /**
     * Tests variable substitution in string (two variable) - French
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testVariableSubstitutionTwoFrench()
    {
        $language   = $this->_config['tr']['fr'];
        $params     = array('content' => $language);
        $translator = new TrNA($params);

        $vars     = array(
                        'song'   => 'Dust in the wind',
                        'artist' => 'Kansas',
                    );
        $expected = 'La chanson est Dust in the wind (Kansas)';
        $actual   = $translator->_('song-key', $vars);

        $this->assertEquals(
            $expected,
            $actual,
            'Translator does not translate French correctly - many parameters'
        );
    }
}