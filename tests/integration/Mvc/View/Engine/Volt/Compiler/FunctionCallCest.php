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

        $expected = $example['expected'];
        $actual   = $volt->compileString($example['source']);

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
                'expected' => '<?= $this->partial(\'abc.volt\') ?>',
            ],
            // Phalcon\Tag
            [
                'label'    => 'link_to',
                'source'   => '{{ link_to(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::linkTo([\'abc\']) ?>',
            ],
            [
                'label'    => 'image',
                'source'   => '{{ image(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::image([\'abc\']) ?>',
            ],
            [
                'label'    => 'formLegacy',
                'source'   => '{{ form_legacy(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::formLegacy([\'abc\']) ?>',
            ],
            [
                'label'    => 'submit_button',
                'source'   => '{{ submit_button(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::submitButton([\'abc\']) ?>',
            ],
            [
                'label'    => 'radio_field',
                'source'   => '{{ radio_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::radioField([\'abc\']) ?>',
            ],
            [
                'label'    => 'check_field',
                'source'   => '{{ check_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::checkField([\'abc\']) ?>',
            ],
            [
                'label'    => 'file_field',
                'source'   => '{{ file_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::fileField([\'abc\']) ?>',
            ],
            [
                'label'    => 'hidden_field',
                'source'   => '{{ hidden_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::hiddenField([\'abc\']) ?>',
            ],
            [
                'label'    => 'password_field',
                'source'   => '{{ password_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::passwordField([\'abc\']) ?>',
            ],
            [
                'label'    => 'text_area',
                'source'   => '{{ text_area(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::textArea([\'abc\']) ?>',
            ],
            [
                'label'    => 'text_field',
                'source'   => '{{ text_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::textField([\'abc\']) ?>',
            ],
            [
                'label'    => 'email_field',
                'source'   => '{{ email_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::emailField([\'abc\']) ?>',
            ],
            [
                'label'    => 'date_field',
                'source'   => '{{ date_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::dateField([\'abc\']) ?>',
            ],
            [
                'label'    => 'tel_field',
                'source'   => '{{ tel_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::telField([\'abc\']) ?>',
            ],
            [
                'label'    => 'numeric_field',
                'source'   => '{{ numeric_field(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::numericField([\'abc\']) ?>',
            ],
            [
                'label'    => 'image_input',
                'source'   => '{{ image_input(\'abc\') }}',
                'expected' => '<?= \Phalcon\Tag::imageInput([\'abc\']) ?>',
            ],
            [
                'label'    => 'url',
                'source'   => '{{ url(\'abc\') }}',
                'expected' => '<?= $this->url->get(\'abc\') ?>',
            ],
            [
                'label'    => 'static_url',
                'source'   => '{{ static_url(\'abc\') }}',
                'expected' => '<?= $this->url->getStatic(\'abc\') ?>',
            ],
            [
                'label'    => 'date',
                'source'   => '{{ date(\'abc\') }}',
                'expected' => '<?= date(\'abc\') ?>',
            ],
            [
                'label'    => 'time',
                'source'   => '{{ time() }}',
                'expected' => '<?= time() ?>',
            ],
            [
                'label'    => 'dump',
                'source'   => '{{ dump(\'abc\') }}',
                'expected' => '<?= var_dump(\'abc\') ?>',
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
                'source'   => '{{ constant(\'abc\') }}',
                'expected' => '<?= constant(\'abc\') ?>',
            ],
            [
                'label'    => 'preload',
                'source'   => '{{ preload(\'abc.css\') }}',
                'expected' => '<?= $this->preload(\'abc.css\') ?>',
            ],
            [
                'label'    => 'preload array',
                'source'   => '{{ preload(\'abc.jpg\', [\'as\' : \'image\']) }}',
                'expected' => '<?= $this->preload(\'abc.jpg\', [\'as\' => \'image\']) ?>',
            ],
            [
                'label'    => 'somefunction',
                'source'   => '{{ somefunction(\'abc\') }}',
                'expected' => '<?= $this->callMacro(\'somefunction\', [\'abc\']) ?>',
            ],
            [
                'label'    => 'length',
                'source'   => '{{ "abc" | length }}',
                'expected' => '<?= $this->length(\'abc\') ?>',
            ],
            [
                'label'    => 'e',
                'source'   => '{{ "abc" | e }}',
                'expected' => '<?= $this->escaper->html(\'abc\') ?>',
            ],
            [
                'label'    => 'escape',
                'source'   => '{{ "abc" | escape }}',
                'expected' => '<?= $this->escaper->html(\'abc\') ?>',
            ],
            [
                'label'    => 'escape_css',
                'source'   => '{{ "abc" | escape_css }}',
                'expected' => '<?= $this->escaper->css(\'abc\') ?>',
            ],
            [
                'label'    => 'escape_js',
                'source'   => '{{ "abc" | escape_js }}',
                'expected' => '<?= $this->escaper->js(\'abc\') ?>',
            ],
            [
                'label'    => 'escape_attr',
                'source'   => '{{ "abc" | escape_attr }}',
                'expected' => '<?= $this->escaper->attributes(\'abc\') ?>',
            ],
            [
                'label'    => 'trim',
                'source'   => '{{ "abc" | trim }}',
                'expected' => '<?= trim(\'abc\') ?>',
            ],
            [
                'label'    => 'left_trim',
                'source'   => '{{ "abc" | left_trim }}',
                'expected' => '<?= ltrim(\'abc\') ?>',
            ],
            [
                'label'    => 'right_trim',
                'source'   => '{{ "abc" | right_trim }}',
                'expected' => '<?= rtrim(\'abc\') ?>',
            ],
            [
                'label'    => 'striptags',
                'source'   => '{{ "abc" | striptags }}',
                'expected' => '<?= strip_tags(\'abc\') ?>',
            ],
            [
                'label'    => 'url_encode',
                'source'   => '{{ "abc" | url_encode }}',
                'expected' => '<?= urlencode(\'abc\') ?>',
            ],
            [
                'label'    => 'striptags',
                'source'   => '{{ "abc" | striptags }}',
                'expected' => '<?= strip_tags(\'abc\') ?>',
            ],
            [
                'label'    => 'slashes',
                'source'   => '{{ "abc" | slashes }}',
                'expected' => '<?= addslashes(\'abc\') ?>',
            ],
            [
                'label'    => 'stripslashes',
                'source'   => '{{ "abc" | stripslashes }}',
                'expected' => '<?= stripslashes(\'abc\') ?>',
            ],
            [
                'label'    => 'nl2br',
                'source'   => '{{ "abc" | nl2br }}',
                'expected' => '<?= nl2br(\'abc\') ?>',
            ],
            [
                'label'    => 'keys',
                'source'   => '{{ "abc" | keys }}',
                'expected' => '<?= array_keys(\'abc\') ?>',
            ],
            [
                'label'    => 'join',
                'source'   => '{{ ["abc", "def"] | join(",") }}',
                'expected' => '<?= join(\',\', [\'abc\', \'def\']) ?>',
            ],
            [
                'label'    => 'lower',
                'source'   => '{{ "abc" | lower }}',
                'expected' => '<?= $this->helper->lower(\'abc\') ?>',
            ],
            [
                'label'    => 'lowercase',
                'source'   => '{{ "abc" | lowercase }}',
                'expected' => '<?= $this->helper->lower(\'abc\') ?>',
            ],
            [
                'label'    => 'upper',
                'source'   => '{{ "abc" | upper }}',
                'expected' => '<?= $this->helper->upper(\'abc\') ?>',
            ],
            [
                'label'    => 'uppercase',
                'source'   => '{{ "abc" | uppercase }}',
                'expected' => '<?= $this->helper->upper(\'abc\') ?>',
            ],
            [
                'label'    => 'capitalize',
                'source'   => '{{ "abc" | capitalize }}',
                'expected' => '<?= ucwords(\'abc\') ?>',
            ],
            [
                'label'    => 'sort',
                'source'   => '{{ "abc" | sort }}',
                'expected' => '<?= $this->sort(\'abc\') ?>',
            ],
            [
                'label'    => 'json_encode',
                'source'   => '{{ "abc" | json_encode }}',
                'expected' => '<?= json_encode(\'abc\') ?>',
            ],
            [
                'label'    => 'json_decode',
                'source'   => '{{ "abc" | json_decode }}',
                'expected' => '<?= json_decode(\'abc\') ?>',
            ],
            [
                'label'    => 'format',
                'source'   => '{{ "abc" | format }}',
                'expected' => '<?= sprintf(\'abc\') ?>',
            ],
            [
                'label'    => 'abs',
                'source'   => '{{ "abc" | abs }}',
                'expected' => '<?= abs(\'abc\') ?>',
            ],
            [
                'label'    => 'slice',
                'source'   => '{{ "abc" | slice }}',
                'expected' => '<?= $this->slice(\'abc\') ?>',
            ],
            [
                'label'    => 'default',
                'source'   => '{{ "abc" | default("def") }}',
                'expected' => '<?= (empty(\'abc\') ? (\'def\') : (\'abc\')) ?>',
            ],
            [
                'label'    => 'convert_encoding',
                'source'   => '{{ "abc" | convert_encoding }}',
                'expected' => '<?= $this->convertEncoding(\'abc\') ?>',
            ],
            // Tag Factory
            [
                'label'    => 'a',
                'source'   => '{{ a("https://phalcon.io/", "home") }}',
                'expected' => '<?= $this->tag->a("https://phalcon.io/", "home") ?>',
            ],
            [
                'label'    => 'base',
                'source'   => '{{ base("https://phalcon.io/") }}',
                'expected' => '<?= $this->tag->base("https://phalcon.io/") ?>',
            ],
            [
                'label'    => 'body',
                'source'   => '{{ body() }}',
                'expected' => '<?= $this->tag->body() ?>',
            ],
            [
                'label'    => 'button',
                'source'   => '{{ button("close", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->button("close", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'close',
                'source'   => '{{ close("form") }}',
                'expected' => '<?= $this->tag->close("form") ?>',
            ],
            [
                'label'    => 'doctype',
                'source'   => '{{ doctype(5, "\n\n") }}',
                'expected' => '<?= $this->tag->doctype(5, "\n\n") ?>',
            ],
            [
                'label'    => 'element',
                'source'   => '{{ element("button", "close", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->element("button", "close", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'form',
                'source'   => '{{ form(["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->form([\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'img',
                'source'   => '{{ img("/img/abc.jpg") }}',
                'expected' => '<?= $this->tag->img("/img/abc.jpg") ?>',
            ],
            [
                'label'    => 'inputCheckbox',
                'source'   => '{{ inputCheckbox("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputCheckbox("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputColor',
                'source'   => '{{ inputColor("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputColor("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputDate',
                'source'   => '{{ inputDate("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputDate("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputDateTime',
                'source'   => '{{ inputDateTime("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputDateTime("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputDateTimeLocal',
                'source'   => '{{ inputDateTimeLocal("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputDateTimeLocal("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputEmail',
                'source'   => '{{ inputEmail("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputEmail("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputFile',
                'source'   => '{{ inputFile("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputFile("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputHidden',
                'source'   => '{{ inputHidden("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputHidden("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputImage',
                'source'   => '{{ inputImage("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputImage("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputInput',
                'source'   => '{{ inputInput("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputInput("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputMonth',
                'source'   => '{{ inputMonth("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputMonth("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputNumeric',
                'source'   => '{{ inputNumeric("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputNumeric("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputPassword',
                'source'   => '{{ inputPassword("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputPassword("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputRadio',
                'source'   => '{{ inputRadio("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputRadio("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputRange',
                'source'   => '{{ inputRange("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputRange("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputSearch',
                'source'   => '{{ inputSearch("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputSearch("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputSelect',
                'source'   => '{{ inputSelect("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputSelect("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputSubmit',
                'source'   => '{{ inputSubmit("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputSubmit("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputTel',
                'source'   => '{{ inputTel("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputTel("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputText',
                'source'   => '{{ inputText("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputText("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputTextarea',
                'source'   => '{{ inputTextarea("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputTextarea("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputTime',
                'source'   => '{{ inputTime("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputTime("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputUrl',
                'source'   => '{{ inputUrl("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputUrl("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'inputWeek',
                'source'   => '{{ inputWeek("test", "1", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->inputWeek("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'label',
                'source'   => '{{ label("test", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->label("test", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'link',
                'source'   => '{{ link("\t", "\n\n") }}',
                'expected' => '<?= $this->tag->link("\t", "\n\n") ?>',
            ],
            [
                'label'    => 'meta',
                'source'   => '{{ meta("\t", "\n\n") }}',
                'expected' => '<?= $this->tag->meta("\t", "\n\n") ?>',
            ],
            [
                'label'    => 'ol',
                'source'   => '{{ ol("test", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->ol("test", [\'class\' => "label label-info"]) ?>',
            ],
            [
                'label'    => 'script',
                'source'   => '{{ script("\t", "\n\n") }}',
                'expected' => '<?= $this->tag->script("\t", "\n\n") ?>',
            ],
            [
                'label'    => 'style',
                'source'   => '{{ style("\t", "\n\n") }}',
                'expected' => '<?= $this->tag->style("\t", "\n\n") ?>',
            ],
            [
                'label'    => 'style',
                'source'   => '{{ style("\t", "\n\n") }}',
                'expected' => '<?= $this->tag->style("\t", "\n\n") ?>',
            ],
            [
                'label'    => 'title',
                'source'   => '{{ title("\t", "\n\n") }}',
                'expected' => '<?= $this->tag->title("\t", "\n\n") ?>',
            ],
            [
                'label'    => 'ul',
                'source'   => '{{ ul("test", ["class" : "label label-info"]) }}',
                'expected' => '<?= $this->tag->ul("test", [\'class\' => "label label-info"]) ?>',
            ],
        ];
    }
}
