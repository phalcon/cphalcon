<?php
namespace Phalcon\Mvc;
use Codeception\Util\Stub;

class UrlTest extends \Codeception\TestCase\Test
{
   /**
    * @var \CodeGuy
    */
    protected $codeGuy;

    protected function _before()
    {
        $_SERVER['PHP_SELF'] = '/';
        $this->codeGuy->addService('router', new Router(false));
    }

    public function testLocalUrl()
    {
        $_SERVER['PHP_SELF'] = '/index.php';
        $url = new Url();
        expect($url->get('classes/api/Some'))->equals('/classes/api/Some');
    }

    public function testUrlForClontroller()
    {
        $this->router()
            ->add('/api/classes/{class}')
            ->setName('classApi');

        expect(
            $this->url()->get(array(
                'for'   => 'classApi',
                'class' => 'Some'
            ))
        )->equals('/api/classes/Some');
    }

    public function testUrlForControllerAction()
    {
        $this->router()
            ->add('/admin/:controller/p/:action', array('controller' => 1, 'action'=> 2))
            ->setName('adminProducts');

        expect(
            $this->url()->get(array(
                'for'        => 'adminProducts',
                'controller' => 'products',
                'action'     => 'index',
            ))
        )->equals('/admin/products/p/index');
    }

    public function testUrlForBlogMixedParameters()
    {
        $this->router()
            ->add('/{year}/{month}/{title}')
            ->setName('blogPost');

        expect(
            $this->url()->get(array(
                'for'   => 'blogPost',
                'year'  => '2010',
                'month' => '10',
                'title' => 'cloudflare-anade-recursos-a-tu-servidor',
            ))
        )->equals('/2010/10/cloudflare-anade-recursos-a-tu-servidor');
    }

    public function testUrlForDifferentLanguage()
    {
        $this->router()
            ->add('/([a-z]{2})/([a-zA-Z0-9_-]+)(/|)', array(
                'lang'       => 1,
                'module'     => 'main',
                'controller' => 2,
                'action'     => 'index'))
            ->setName('lang-controller');

        expect(
            $this->url()->get(array(
                'for'        => 'lang-controller',
                'lang'       => 'de',
                'controller' => 'index',
            ))
        )->equals('/de/index');
    }

    public function testUrlForExternalSite()
    {        
        $this->router()
            ->add('/wiki/{article:[a-z]+}')
            ->setName('wikipedia');

        $params   = array(
            'for'     => 'wikipedia',
            'article' => 'Television_news',
        );
        expect($this->url()->get($params))->equals('/wiki/Television_news');
    }

    public function testNonExistingUrl()
    {
        $this->setExpectedException('Phalcon\Mvc\Url\Exception');
        $this->url()->get(array(
            'for'     => 'some-url',
            'param' => 'no-such-param',
        ));
    }


    /**
     * @return Router
     */
    protected function router()
    {
        return $this->codeGuy->getService('router');
    }

    /**
     * @return Url
     */
    protected function url()
    {
        $url = new Url;
        return $this->codeGuy->withDi($url);
    }

}
