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

namespace Phalcon\Tests\Integration\Mvc\View\Engine\Volt\Compiler;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function substr;

/**
 * Class FunctionCallCest
 */
class FunctionCallCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: functionCall()
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataProvider getExamples
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-11
     */
    public function mvcViewEngineVoltCompilerFunctionCall(IntegrationTester $I, Example $example)
    {
        $I->wantToTest(
            'Mvc\View\Engine\Volt\Compiler - functionCall() ' . $example['label']
        );

        $this->setNewFactoryDefault();

        $volt = new Compiler();
        $volt->setDI($this->container);

        $expected = $example['source'];
        $actual   = $volt->compileString($example['expected']);

        $I->assertSame($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'label'    => 'get_content',
                'source'   => '{{ content() }}',
                'expected' => '<?= $this->getContent() ?>',
            ],
            [
                'label'    => 'content',
                'source'   => '{{ content() }}',
                'expected' => '<?= $this->getContent() ?>',
            ],
            [
                'label'    => 'partial',
                'source'   => '{{ partial("abc.volt") }}',
                'expected' => '<?= $this->partial("abc.volt") ?>',
            ],
            [
                'label'    => 'link_to',
                'source'   => '{{ link_to("abc") }}',
                'expected' => '<?= \Phalcon\Tag::linkTo(["abc"]) ?>',
            ],
            [
                'label'    => 'image',
                'source'   => '{{ image("abc") }}',
                'expected' => '<?= \Phalcon\Tag::image(["abc"]) ?>',
            ],
            [
                'label'    => 'form',
                'source'   => '{{ form("abc") }}',
                'expected' => '<?= \Phalcon\Tag::form(["abc"]) ?>',
            ],
            [
                'label'    => 'submit_button',
                'source'   => '{{ submit_button("abc") }}',
                'expected' => '<?= \Phalcon\Tag::submitButton(["abc"]) ?>',
            ],
            [
                'label'    => 'radio_field',
                'source'   => '{{ radio_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::radioField(["abc"]) ?>',
            ],
            [
                'label'    => 'check_field',
                'source'   => '{{ check_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::checkField(["abc"]) ?>',
            ],
            [
                'label'    => 'file_field',
                'source'   => '{{ file_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::fileField(["abc"]) ?>',
            ],
            [
                'label'    => 'hidden_field',
                'source'   => '{{ hidden_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::hiddenField(["abc"]) ?>',
            ],
            [
                'label'    => 'password_field',
                'source'   => '{{ password_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::passwordField(["abc"]) ?>',
            ],
            [
                'label'    => 'text_area',
                'source'   => '{{ text_area("abc") }}',
                'expected' => '<?= \Phalcon\Tag::textArea(["abc"]) ?>',
            ],
            [
                'label'    => 'text_field',
                'source'   => '{{ text_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::textField(["abc"]) ?>',
            ],
            [
                'label'    => 'email_field',
                'source'   => '{{ email_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::emailField(["abc"]) ?>',
            ],
            [
                'label'    => 'date_field',
                'source'   => '{{ date_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::dateField(["abc"]) ?>',
            ],
            [
                'label'    => 'tel_field',
                'source'   => '{{ tel_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::telField(["abc"]) ?>',
            ],
            [
                'label'    => 'numeric_field',
                'source'   => '{{ numeric_field("abc") }}',
                'expected' => '<?= \Phalcon\Tag::numericField(["abc"]) ?>',
            ],
            [
                'label'    => 'image_input',
                'source'   => '{{ image_input("abc") }}',
                'expected' => '<?= \Phalcon\Tag::imageInput(["abc"]) ?>',
            ],
            [
                'label'    => 'url',
                'source'   => '{{ url("abc") }}',
                'expected' => '<?= $this->url->get("abc") ?>',
            ],
            [
                'label'    => 'static_url',
                'source'   => '{{ static_url("abc") }}',
                'expected' => '<?= $this->url->getStatic("abc") ?>',
            ],
            [
                'label'    => 'date',
                'source'   => '{{ date("abc") }}',
                'expected' => '<?= date("abc") ?>',
            ],
            [
                'label'    => 'time',
                'source'   => '{{ time() }}',
                'expected' => '<?= time() ?>',
            ],
            [
                'label'    => 'dump',
                'source'   => '{{ dump("abc") }}',
                'expected' => '<?= var_dump("abc") ?>',
            ],
            [
                'label'    => 'version',
                'source'   => '{{ version() }}',
                'expected' => '<?= (new Phalcon\Support\Version)->get() ?>',
            ],
            [
                'label'    => 'version_id',
                'source'   => '{{ version_id() }}',
                'expected' => '<?= (new Phalcon\Support\Version)->getId() ?>',
            ],
            [
                'label'    => 'constant',
                'source'   => '{{ constant("abc") }}',
                'expected' => '<?= constant("abc") ?>',
            ],
            [
                'label'    => 'preload',
                'source'   => '{{ preload("abc.css") }}',
                'expected' => '<?= $this->preload("abc.css") ?>',
            ],
            [
                'label'    => 'preload array',
                'source'   => '{{ preload("abc.jpg", ["as" : "image"]) }}',
                'expected' => '<?= $this->preload("abc.jpg", [\'as\' => "image"]) ?>',
            ],
            [
                'label'    => 'somefunction',
                'source'   => '{{ somefunction("abc") }}',
                'expected' => '<?= $this->callMacro(\'somefunction\', ["abc"]) ?>',
            ],
            [
                'label'    => 'length',
                'source'   => '{{ "abc" | length }}',
                'expected' => '<?= $this->length("abc") ?>',
            ],
            [
                'label'    => 'e',
                'source'   => '{{ "abc" | e }}',
                'expected' => '<?= $this->escaper->html("abc") ?>',
            ],
            [
                'label'    => 'escape',
                'source'   => '{{ "abc" | escape }}',
                'expected' => '<?= $this->escaper->html("abc") ?>',
            ],
            [
                'label'    => 'escape_css',
                'source'   => '{{ "abc" | escape_css }}',
                'expected' => '<?= $this->escaper->css("abc") ?>',
            ],
            [
                'label'    => 'escape_js',
                'source'   => '{{ "abc" | escape_js }}',
                'expected' => '<?= $this->escaper->js("abc") ?>',
            ],
            [
                'label'    => 'escape_attr',
                'source'   => '{{ "abc" | escape_attr }}',
                'expected' => '<?= $this->escaper->attributes("abc") ?>',
            ],
            [
                'label'    => 'trim',
                'source'   => '{{ "abc" | trim }}',
                'expected' => '<?= trim("abc") ?>',
            ],
            [
                'label'    => 'left_trim',
                'source'   => '{{ "abc" | left_trim }}',
                'expected' => '<?= ltrim("abc") ?>',
            ],
            [
                'label'    => 'right_trim',
                'source'   => '{{ "abc" | right_trim }}',
                'expected' => '<?= rtrim("abc") ?>',
            ],
            [
                'label'    => 'striptags',
                'source'   => '{{ "abc" | striptags }}',
                'expected' => '<?= strip_tags("abc") ?>',
            ],
            [
                'label'    => 'url_encode',
                'source'   => '{{ "abc" | url_encode }}',
                'expected' => '<?= urlencode("abc") ?>',
            ],
            [
                'label'    => 'striptags',
                'source'   => '{{ "abc" | striptags }}',
                'expected' => '<?= strip_tags("abc") ?>',
            ],
            [
                'label'    => 'slashes',
                'source'   => '{{ "abc" | slashes }}',
                'expected' => '<?= addslashes("abc") ?>',
            ],
            [
                'label'    => 'stripslashes',
                'source'   => '{{ "abc" | stripslashes }}',
                'expected' => '<?= stripslashes("abc") ?>',
            ],
            [
                'label'    => 'nl2br',
                'source'   => '{{ "abc" | nl2br }}',
                'expected' => '<?= nl2br("abc") ?>',
            ],
            [
                'label'    => 'keys',
                'source'   => '{{ "abc" | keys }}',
                'expected' => '<?= array_keys("abc") ?>',
            ],
            [
                'label'    => 'join',
                'source'   => '{{ ["abc", "def"] | join(",") }}',
                'expected' => '<?= join(\',\', ["abc", "def"]) ?>',
            ],
            [
                'label'    => 'lower',
                'source'   => '{{ "abc" | lower }}',
                'expected' => '<?= strtolower("abc") ?>',
            ],
            [
                'label'    => 'lowercase',
                'source'   => '{{ "abc" | lowercase }}',
                'expected' => '<?= strtolower("abc") ?>',
            ],
            [
                'label'    => 'upper',
                'source'   => '{{ "abc" | upper }}',
                'expected' => '<?= strtoupper("abc") ?>',
            ],
            [
                'label'    => 'uppercase',
                'source'   => '{{ "abc" | uppercase }}',
                'expected' => '<?= strtoupper("abc") ?>',
            ],
            [
                'label'    => 'capitalize',
                'source'   => '{{ "abc" | capitalize }}',
                'expected' => '<?= ucwords("abc") ?>',
            ],
            [
                'label'    => 'sort',
                'source'   => '{{ "abc" | sort }}',
                'expected' => '<?= $this->sort("abc") ?>',
            ],
            [
                'label'    => 'json_encode',
                'source'   => '{{ "abc" | json_encode }}',
                'expected' => '<?= json_encode("abc") ?>',
            ],
            [
                'label'    => 'json_decode',
                'source'   => '{{ "abc" | json_decode }}',
                'expected' => '<?= json_decode("abc") ?>',
            ],
            [
                'label'    => 'format',
                'source'   => '{{ "abc" | format }}',
                'expected' => '<?= sprintf("abc") ?>',
            ],
            [
                'label'    => 'abs',
                'source'   => '{{ "abc" | abs }}',
                'expected' => '<?= abs("abc") ?>',
            ],
            [
                'label'    => 'slice',
                'source'   => '{{ "abc" | slice }}',
                'expected' => '<?= $this->slice("abc") ?>',
            ],
            [
                'label'    => 'default',
                'source'   => '{{ "abc" | default("def") }}',
                'expected' => '<?= (empty("abc") ? ("def") : ("abc")) ?>',
            ],
            [
                'label'    => 'convert_encoding',
                'source'   => '{{ "abc" | convert_encoding }}',
                'expected' => '<?= $this->convertEncoding("abc") ?>',
            ],
            [
                'label'    => 'title',
                'source'   => '{{ tag.title("\t", "\n\n") }}',
                'expected' => '<?= $this->tag->title("\t", "\n\n") ?>',
            ],
        ];
    }
}
