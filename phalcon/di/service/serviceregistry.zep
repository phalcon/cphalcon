namespace Phalcon\Di\Service;

use Phalcon\DiInterface;
use Phalcon\Di\Exception;
use Phalcon\Di\ServiceInterface;
use Phalcon\Config\Adapter\Yaml;

/**
 * Phalcon\Di\Service\ServiceRegistry
 *
 **/
class ServiceRegistry
{

	protected di;

	/**
	 *
	 */
	public function __construct(<DiInterface> di)
	{
		let this->di = di;
	}

	/**
	 *
	 */
	public function registerDir(dirPath)
	{
		var dirPathItem;

		switch (gettype(dirPath)) {
			case "string":
				this->registerDirInternal(dirPath);
				break;
			case "array":
			case "object":
				for dirPathItem in iterator(dirPath) {
					this->registerDirInternal(dirPathItem);
				}
				break;
			default:
				throw new Exception("Invalid services.");
				break;
		}
	}

	/**
	 *
	 */
	protected function registerDirInternal(string! dirPath)
	{
		var dir, fileinfo, extension, serviceNameSection, forceShared, serviceName;

		let dir = new \DirectoryIterator(dirPath);
		for fileinfo in iterator(dir) {
			if (fileinfo->isDir()) {
				continue;
			}

			let extension = fileinfo->getExtension();
			let serviceNameSection = fileinfo->getBasename("." . extension);

			let forceShared = substr(serviceNameSection, -7) === "_shared";
			let serviceName = forceShared ? substr(serviceNameSection, 0, -7) : serviceNameSection;

			this->registerFile(fileinfo->getPathname(), serviceName, extension, forceShared);
		}
	}

	/**
	 *
	 */
	protected function registerFile(string! path, string! serviceName, string! extension, boolean forceShared)
	{
		var serviceDef;

		switch extension {
			case "php":
				let serviceDef = require path;

				switch typeof serviceDef {
					case "object":
						if (serviceDef instanceof ServiceInterface) {
							if (forceShared) {
								serviceDef->setShared(true);
							}
							this->di->setRaw(serviceName, serviceDef);
						} elseif (is_callable(serviceDef)) {
							this->di->set(serviceName, serviceDef, forceShared);
						} else {
							throw new Exception("Invalid service object definiton.");
						}
						break;
					case "array":
					case "string":
						this->di->set(serviceName, serviceDef, forceShared);
						break;
					default:
						throw new Exception("Invalid service definiton.");
				}
				break;
			case "yml":
				let serviceDef = new Yaml(path);
				this->di->set(serviceName, serviceDef->toArray(), forceShared);
				break;
			default:
				throw new Exception("Invalid service definition type.");
				break;
		}
	}
}
